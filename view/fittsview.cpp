#include "fittsview.h"
#include "graphicwidget.h"
#include "../controller/fittscontroller.h"
#include "../model/fittsmodel.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPushButton>

#include <QStackedLayout>
#include <QGraphicsView>
#include <QChart>
#include <QPolarChart>
#include <QLineSeries>

QT_CHARTS_USE_NAMESPACE

FittsView::FittsView(FittsModel *fittsModel) : QMainWindow() {
    this->fittsModel = fittsModel;

    this->initWindows();
    this->fittsController = new FittsController(this, this->fittsModel);

    // Btn clicked
    connect(leaveBtn,SIGNAL(clicked()),fittsController,SLOT(quit()));
    connect(startBtn,SIGNAL(clicked()),fittsController,SLOT(startSimulation()));

    connect(backBtn,SIGNAL(clicked()),fittsController,SLOT(backToSettings()));
    connect(resultBtn,SIGNAL(clicked()),fittsController,SLOT(resultClicked()));

    connect(resultLeaveBtn,SIGNAL(clicked()),fittsController,SLOT(quit()));
    connect(restartBtn,SIGNAL(clicked()),fittsController,SLOT(backToSettings()));

    connect(graphicView, SIGNAL(mouseClicked(int,int)), fittsController, SLOT(cibleClicked(int,int)));

    // SpinBox values update
    connect(aValue,SIGNAL(valueChanged(double)),fittsController,SLOT(aValueChanged(double)));
    connect(bValue,SIGNAL(valueChanged(double)),fittsController,SLOT(bValueChanged(double)));
    connect(nbCible,SIGNAL(valueChanged(int)),fittsController,SLOT(nbCibleChanged(int)));
    connect(minSize,SIGNAL(valueChanged(int)),fittsController,SLOT(minSizeChanged(int)));
    connect(maxSize,SIGNAL(valueChanged(int)),fittsController,SLOT(maxSizeChanged(int)));
}

FittsView::~FittsView() {}

void FittsView::initWindows() {

    QWidget *mainWidget = new QWidget;
    this->setCentralWidget(mainWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(mainWidget);

    mainStack = new QStackedLayout;
    mainLayout->addLayout(mainStack);

    QWidget *settingsWidget = new QWidget;
    mainStack->addWidget(settingsWidget);

    QVBoxLayout *settingsLayout = new QVBoxLayout(settingsWidget);


    QLabel *label;

    label = new QLabel("Programme pour vérifier la loi Fitts");
    label->setAlignment(Qt::AlignCenter);
    label->setFont(QFont("Arial",20));
    settingsLayout->addWidget(label);


    QGroupBox *rappelBox = new QGroupBox("Rappel :");
    settingsLayout->addWidget(rappelBox);
    QHBoxLayout *rappelLayout = new QHBoxLayout(rappelBox);

    QVBoxLayout *rappelLeftLayout = new QVBoxLayout();
    rappelLayout->addLayout(rappelLeftLayout,2);

    label = new QLabel("Formule utilisée:");
    rappelLeftLayout->addWidget(label);

    label = new QLabel;
    label->setPixmap(QPixmap("./data/formule.png").scaled(200,100,Qt::KeepAspectRatio));
    rappelLeftLayout->addWidget(label);

    QGridLayout *rappelRightLayout = new QGridLayout();
    rappelLayout->addLayout(rappelRightLayout,1);

    label = new QLabel("Choix de a et b");
    rappelRightLayout->addWidget(label,0,0,1,2);

    rappelRightLayout->addWidget(new QLabel("Variable a "),1,0);
    rappelRightLayout->addWidget(new QLabel("Variable b "),2,0);

    aValue = new QDoubleSpinBox;
    aValue->setValue(this->fittsModel->a);
    rappelRightLayout->addWidget(aValue,1,1);


    bValue = new QDoubleSpinBox;
    bValue->setValue(this->fittsModel->b);
    rappelRightLayout->addWidget(bValue,2,1);


    QGroupBox *configBox = new QGroupBox("Configuration du test :");
    settingsLayout->addWidget(configBox);
    QGridLayout *configLayout = new QGridLayout(configBox);

    configLayout->addWidget(new QLabel("Nombre de cibles:"),1,0);
    configLayout->addWidget(new QLabel("Taille minimum cible:"),2,0);
    configLayout->addWidget(new QLabel("Taille maximal cible:"),3,0);

    nbCible = new QSpinBox;
    nbCible->setValue(this->fittsModel->nbCible);
    nbCible->setMaximum(100);
    configLayout->addWidget(nbCible,1,1);

    minSize = new QSpinBox;
    minSize->setMaximum(1000);
    minSize->setValue(this->fittsModel->minSize);
    configLayout->addWidget(minSize,2,1);

    maxSize = new QSpinBox;
    maxSize->setMaximum(1000);
    maxSize->setValue(this->fittsModel->maxSize);
    configLayout->addWidget(maxSize,3,1);


    QHBoxLayout *btnLayout = new QHBoxLayout;
    settingsLayout->addLayout(btnLayout);

    leaveBtn = new QPushButton("Quitter");
    btnLayout->addWidget(leaveBtn);

    startBtn = new QPushButton("Démarrer");
    btnLayout->addWidget(startBtn);



    // Test part

    QWidget *testWidget = new QWidget;
    mainStack->addWidget(testWidget);

    QVBoxLayout *testLayout = new QVBoxLayout(testWidget);

    testLabel = new QLabel;
    testLayout->addWidget(testLabel);

    graphicView = new GraphicWidget;
    testLayout->addWidget(graphicView);
    graphicView->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff);
    graphicView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene = new QGraphicsScene;
    graphicView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
    graphicView->setScene(scene);
    scene->setSceneRect(0,0,graphicView->width(),300);

    label = new QLabel("Cliquez sur les cibles qui apparaissent en <font color='red'><strong>rouge</strong></font>");
    testLayout->addWidget(label);

    btnLayout = new QHBoxLayout;
    testLayout->addLayout(btnLayout);

    backBtn = new QPushButton("Retour");
    btnLayout->addWidget(backBtn);

    resultBtn = new QPushButton("Résultats");
    btnLayout->addWidget(resultBtn);
    resultBtn->setEnabled(false);

    QWidget *resultWidget = new QWidget;
    mainStack->addWidget(resultWidget);

    QVBoxLayout *resultLayout = new QVBoxLayout(resultWidget);

    plot = new QChartView;
    resultLayout->addWidget(plot);

    QGroupBox *resultBox =  new QGroupBox("Stats");
    resultLayout->addWidget(resultBox);
    QGridLayout *resultBoxLayout = new QGridLayout(resultBox);

    label = new QLabel("Ecart-Type : ");
    resultBoxLayout->addWidget(label,0,0);
    ecartType = new QLabel;
    resultBoxLayout->addWidget(ecartType,0,1);

    label = new QLabel("Erreur-Type : ");
    resultBoxLayout->addWidget(label,1,0);
    erreurType = new QLabel;
    resultBoxLayout->addWidget(erreurType,1,1);

    label = new QLabel("Différence moyenne : ");
    resultBoxLayout->addWidget(label,0,2);
    diffMoy = new QLabel;
    resultBoxLayout->addWidget(diffMoy,0,3);

    label = new QLabel("Intervalle de confiance à 95% : ");
    resultBoxLayout->addWidget(label,1,2);
    itc95 = new QLabel;
    resultBoxLayout->addWidget(itc95,1,3);

    resultBoxLayout->setColumnStretch(1,10);
    resultBoxLayout->setColumnStretch(3,10);

    btnLayout = new QHBoxLayout;
    resultLayout->addLayout(btnLayout);

    resultLeaveBtn = new QPushButton("Quitter");
    btnLayout->addWidget(resultLeaveBtn);

    restartBtn = new QPushButton("Recommencer");
    btnLayout->addWidget(restartBtn);
}

void FittsView::updateTestMsg() {
    this->testLabel->setText("<strong>Le test commencera après avoir appuyé sur la cible bleu.</strong> Nombre de cibles restantes : " + QString::number(this->fittsModel->cibleLeft));
}


void FittsView::displayResults() {
    this->diffMoy->setText(QString::number(this->fittsModel->diffMoy));
    this->ecartType->setText(QString::number(this->fittsModel->ecartType));
    this->erreurType->setText(QString::number(this->fittsModel->erreurType));
    this->itc95->setText(QString::number(this->fittsModel->itc95));
}
