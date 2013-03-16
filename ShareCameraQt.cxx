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
#include <vtkPolyDataReader.h>
#include <QFileDialog>
#include <QString>
// Constructor
ShareCameraQt::ShareCameraQt() 
{
  this->setupUi(this);

  // Sphere
  vtkSmartPointer<vtkSphereSource> sphereSource = vtkSmartPointer<vtkSphereSource>::New();
  sphereSource->Update();
  vtkSmartPointer<vtkPolyDataMapper> sphereMapper =vtkSmartPointer<vtkPolyDataMapper>::New();
  sphereMapper->SetInputConnection(sphereSource->GetOutputPort());
  vtkSmartPointer<vtkActor> sphereActor = vtkSmartPointer<vtkActor>::New();
  sphereActor->SetMapper(sphereMapper);
  
  // Cube
  vtkSmartPointer<vtkCubeSource> cubeSource = vtkSmartPointer<vtkCubeSource>::New();
  cubeSource->Update();
  vtkSmartPointer<vtkPolyDataMapper> cubeMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
  cubeMapper->SetInputConnection(cubeSource->GetOutputPort());
  vtkSmartPointer<vtkActor> cubeActor = vtkSmartPointer<vtkActor>::New();
  cubeActor->SetMapper(cubeMapper);
  
  // VTK Renderer
  vtkSmartPointer<vtkRenderer> leftRenderer = vtkSmartPointer<vtkRenderer>::New();
  leftRenderer->AddActor(sphereActor);
  
  vtkSmartPointer<vtkRenderer> rightRenderer = vtkSmartPointer<vtkRenderer>::New();

  // Add Actor to renderer
  rightRenderer->AddActor(cubeActor);

  // VTK/Qt wedded
  this->qvtkWidgetLeft->GetRenderWindow()->AddRenderer(leftRenderer);
  this->qvtkWidgetRight->GetRenderWindow()->AddRenderer(rightRenderer);

  rightRenderer->ResetCamera();
  leftRenderer->ResetCamera();
  
  rightRenderer->SetActiveCamera(leftRenderer->GetActiveCamera());
    
  // Set up action signals and slots
  connect(this->actionExit, SIGNAL(triggered()), this, SLOT(slotExit()));

  this->qvtkWidgetLeft->GetRenderWindow()->AddObserver(vtkCommand::ModifiedEvent, this, &ShareCameraQt::ModifiedHandler);
  this->qvtkWidgetLeft->GetRenderWindow()->AddObserver(vtkCommand::AnyEvent, this, &ShareCameraQt::ModifiedHandler);

}

void ShareCameraQt::ModifiedHandler() 
{
  this->qvtkWidgetRight->GetRenderWindow()->Render();
}

void ShareCameraQt::slotExit() 
{
  qApp->exit();
}

void ShareCameraQt::on_pushButton_clicked()
{
       QString inputFilename = QFileDialog::getOpenFileName(this,tr("Open Image"),"~",tr("Image Files (*.vtk)"));
       QByteArray arr = inputFilename.toLatin1();
       const char *filename = arr.data();
       vtkSmartPointer<vtkPolyDataReader> meshReader = vtkSmartPointer<vtkPolyDataReader>::New() ;
       meshReader->SetFileName ( filename ) ;
       meshReader->Update () ;
       vtkSmartPointer<vtkPolyDataMapper> sphereMapper =vtkSmartPointer<vtkPolyDataMapper>::New();
       sphereMapper->SetInput(meshReader->GetOutput());
       vtkSmartPointer<vtkActor> sphereActor = vtkSmartPointer<vtkActor>::New();
       sphereActor->SetMapper(sphereMapper);
       inputFilename = QFileDialog::getOpenFileName(this,tr("Open Image"),"~",tr("Image Files (*.vtk)"));
       arr = inputFilename.toLatin1();
       filename = arr.data();
       vtkSmartPointer<vtkPolyDataReader> meshReader2 = vtkSmartPointer<vtkPolyDataReader>::New() ;
       meshReader2->SetFileName ( filename );
       meshReader2->Update ();
       vtkSmartPointer<vtkPolyDataMapper> cubeMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
       cubeMapper->SetInput(meshReader2->GetOutput());
       vtkSmartPointer<vtkActor> cubeActor = vtkSmartPointer<vtkActor>::New();
       cubeActor->SetMapper(cubeMapper);

       // VTK Renderer
       vtkSmartPointer<vtkRenderer> leftRenderer = vtkSmartPointer<vtkRenderer>::New();
       leftRenderer->AddActor(sphereActor);

       vtkSmartPointer<vtkRenderer> rightRenderer = vtkSmartPointer<vtkRenderer>::New();

       // Add Actor to renderer
       rightRenderer->AddActor(cubeActor);

       // VTK/Qt wedded
       vtkRenderer *first = this->qvtkWidgetLeft->GetRenderWindow()->GetRenderers()->GetFirstRenderer();
       while (first != NULL) {
           this->qvtkWidgetLeft->GetRenderWindow()->RemoveRenderer(first);
           first = this->qvtkWidgetLeft->GetRenderWindow()->GetRenderers()->GetNextItem();
       }
       this->qvtkWidgetLeft->GetRenderWindow()->AddRenderer(leftRenderer);
       first = this->qvtkWidgetRight->GetRenderWindow()->GetRenderers()->GetFirstRenderer();
       while (first != NULL) {
           this->qvtkWidgetLeft->GetRenderWindow()->RemoveRenderer(first);
           first = this->qvtkWidgetLeft->GetRenderWindow()->GetRenderers()->GetNextItem();
       }
       this->qvtkWidgetRight->GetRenderWindow()->AddRenderer(rightRenderer);

       rightRenderer->ResetCamera();
       leftRenderer->ResetCamera();

       rightRenderer->SetActiveCamera(leftRenderer->GetActiveCamera());
        //this->qvtkWidgetLeft->GetRenderWindow()->AddObserver(vtkCommand::AnyEvent, this, &ShareCameraQt::ModifiedHandler);

}

void ShareCameraQt::on_pushButton_2_clicked()
{
    this->qvtkWidgetLeft->GetRenderWindow()->Render();
    this->qvtkWidgetRight->GetRenderWindow()->Render();
//     this->qvtkWidgetLeft->GetRenderWindow()->AddObserver(vtkCommand::AnyEvent, this, &ShareCameraQt::ModifiedHandler);

}
