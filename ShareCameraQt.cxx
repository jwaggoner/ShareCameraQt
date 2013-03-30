#include "ShareCameraQt.h"

#include <vtkDataObjectToTable.h>
#include <vtkElevationFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkQtTableView.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRendererCollection.h>
#include <vtkSphereSource.h>
#include <vtkCubeSource.h>
#include "vtkSmartPointer.h"
#include <vtkCamera.h>
#include <vtkPolyDataReader.h>
#include <QFileDialog>
#include <QVectorIterator>
#include <QString>
#include <QStringList>
#include <QDir>
#include <QFileInfoList>
#include <QFileInfoListIterator>
#include <QFileInfo>
// Constructor
ShareCameraQt::ShareCameraQt() 
{
  this->setupUi(this);

    QString dir = QFileDialog::getExistingDirectory(this,tr("Open .vtk Directory"),"~",QFileDialog::ShowDirsOnly);
    QDir vtkDir(dir);
    QFileInfoList list = vtkDir.entryInfoList();
    vtkSmartPointer<vtkRenderer> headRenderer = vtkSmartPointer<vtkRenderer>::New();
    int root = 0;
    for ( ;root*root < list.size()-2;root++);
    int col = 0;
    int row = 0;
    for (int j = 0; j < list.size(); j++) {
        if (j < 2) continue;
        QString path = list.at(j).absoluteFilePath();
        QByteArray arr = path.toLatin1();
        const char *filename = arr.data();
        vtkSmartPointer<vtkPolyDataReader> meshReader = vtkSmartPointer<vtkPolyDataReader>::New() ;
        meshReader->SetFileName ( filename ) ;
        meshReader->Update () ;
        vtkSmartPointer<vtkPolyDataMapper> mapper =vtkSmartPointer<vtkPolyDataMapper>::New();
        mapper->SetInputConnection(meshReader->GetOutputPort());
        vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
        actor->SetMapper(mapper);
        if (j == 0) {
            headRenderer->AddActor(actor);
            QVTKWidget *next = new QVTKWidget(this->gridLayoutWidget);
            this->widgetList->append(next);
            next->GetRenderWindow()->AddRenderer(headRenderer);
            headRenderer->ResetCamera();
        } else {
            vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
            renderer->AddActor(actor);
            QVTKWidget *next = new QVTKWidget(this->gridLayoutWidget);
            this->widgetList->append(next);
            next->GetRenderWindow()->AddRenderer(renderer);
            renderer->SetActiveCamera(headRenderer->GetActiveCamera());
            renderer->ResetCamera();
        }

    }


    for (int i = 0; i < this->widgetList->size();i++) {
        this->gridLayout->addWidget(this->widgetList->value(i),row,col);
        if (col == root) {
            col = 0;
            row++;
        } else {
            col++;
        }
    }
    for (int i = 0; i < this->widgetList->size();i++) {
        this->widgetList->value(i)->GetRenderWindow()->Render();
    }

    // Set up action signals and slots
    connect(this->actionExit, SIGNAL(triggered()), this, SLOT(slotExit()));
    for (int i = 0; i < this->widgetList->size(); i++)
        this->widgetList->value(i)->GetRenderWindow()->AddObserver(vtkCommand::ModifiedEvent, this, &ShareCameraQt::ModifiedHandler);

}

void ShareCameraQt::ModifiedHandler() 
{
    for (int i = 0; i < this->widgetList->size();i++) {
        this->widgetList->value(i)->GetRenderWindow()->Render();
    }
}

void ShareCameraQt::slotExit() 
{
  qApp->exit();
}

void ShareCameraQt::on_pushButton_clicked()
{
    for (int i = 0; i < this->widgetList->size(); i++) {
        this->gridLayout->removeWidget(this->widgetList->value(i));
        delete this->widgetList->value(i);
    }
    this->widgetList->clear();
    QString dir = QFileDialog::getExistingDirectory(this,tr("Open .vtk Directory"),"~",QFileDialog::ShowDirsOnly);
    QDir vtkDir(dir);
    QFileInfoList list = vtkDir.entryInfoList();
    vtkSmartPointer<vtkRenderer> headRenderer = vtkSmartPointer<vtkRenderer>::New();
    int root = 0;
    for ( ;root*root < list.size()-2;root++);
    int col = 0;
    int row = 0;
    for (int j = 0; j < list.size(); j++) {
        if (j < 2) continue;
        QString path = list.at(j).absoluteFilePath();
        QByteArray arr = path.toLatin1();
        const char *filename = arr.data();
        vtkSmartPointer<vtkPolyDataReader> meshReader = vtkSmartPointer<vtkPolyDataReader>::New() ;
        meshReader->SetFileName ( filename ) ;
        meshReader->Update () ;
        vtkSmartPointer<vtkPolyDataMapper> mapper =vtkSmartPointer<vtkPolyDataMapper>::New();
        mapper->SetInputConnection(meshReader->GetOutputPort());
        vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
        actor->SetMapper(mapper);
        if (j == 0) {
            headRenderer->AddActor(actor);
            QVTKWidget *next = new QVTKWidget(this->gridLayoutWidget);
            this->widgetList->append(next);
            next->GetRenderWindow()->AddRenderer(headRenderer);
            headRenderer->ResetCamera();
        } else {
            vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
            renderer->AddActor(actor);
            QVTKWidget *next = new QVTKWidget(this->gridLayoutWidget);
            this->widgetList->append(next);
            next->GetRenderWindow()->AddRenderer(renderer);
            renderer->SetActiveCamera(headRenderer->GetActiveCamera());
            renderer->ResetCamera();
        }

    }
    for (int i = 0; i < this->widgetList->size();i++) {
        this->gridLayout->addWidget(this->widgetList->value(i),row,col);
        if (col == root) {
            col = 0;
            row++;
        } else {
            col++;
        }
    }
    for (int i = 0; i < this->widgetList->size();i++) {
        this->widgetList->value(i)->GetRenderWindow()->Render();
    }

    // Set up action signals and slots
    connect(this->actionExit, SIGNAL(triggered()), this, SLOT(slotExit()));
    for (int i = 0; i < this->widgetList->size(); i++)
        this->widgetList->value(i)->GetRenderWindow()->AddObserver(vtkCommand::ModifiedEvent, this, &ShareCameraQt::ModifiedHandler);
}

