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
#include <QString>
// Constructor
ShareCameraQt::ShareCameraQt() 
{
  this->setupUi(this);

  // Sphere
    QString inputFilename = QFileDialog::getOpenFileName(this,tr("Open Image"),"~",tr("Image Files (*.vtk)"));
    QByteArray arr = inputFilename.toLatin1();
    const char *filename = arr.data();
    vtkSmartPointer<vtkPolyDataReader> meshReader = vtkSmartPointer<vtkPolyDataReader>::New() ;
    meshReader->SetFileName ( filename ) ;
    meshReader->Update () ;
    vtkSmartPointer<vtkPolyDataMapper> sphereMapper =vtkSmartPointer<vtkPolyDataMapper>::New();
    sphereMapper->SetInputConnection(meshReader->GetOutputPort());
    vtkSmartPointer<vtkActor> sphereActor = vtkSmartPointer<vtkActor>::New();
    sphereActor->SetMapper(sphereMapper);
    inputFilename = QFileDialog::getOpenFileName(this,tr("Open Image"),"~",tr("Image Files (*.vtk)"));
    arr = inputFilename.toLatin1();
    filename = arr.data();
    vtkSmartPointer<vtkPolyDataReader> meshReader2 = vtkSmartPointer<vtkPolyDataReader>::New() ;
    meshReader2->SetFileName ( filename );
    meshReader2->Update ();
    vtkSmartPointer<vtkPolyDataMapper> cubeMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    cubeMapper->SetInputConnection(meshReader2->GetOutputPort());
    vtkSmartPointer<vtkActor> cubeActor = vtkSmartPointer<vtkActor>::New();
    cubeActor->SetMapper(cubeMapper);
    
    // VTK Renderer
    vtkSmartPointer<vtkRenderer> leftRenderer = vtkSmartPointer<vtkRenderer>::New();
    leftRenderer->AddActor(sphereActor);
    
    vtkSmartPointer<vtkRenderer> rightRenderer = vtkSmartPointer<vtkRenderer>::New();
    
    // Add Actor to renderer
    rightRenderer->AddActor(cubeActor);
    this->qvtkWidgetLeft = new QVTKWidget(this->gridLayoutWidget);
    this->qvtkWidgetRight = new QVTKWidget(this->gridLayoutWidget);
    // VTK/Qt wedded
    this->qvtkWidgetLeft->GetRenderWindow()->AddRenderer(leftRenderer);
    this->qvtkWidgetRight->GetRenderWindow()->AddRenderer(rightRenderer);
    
    rightRenderer->ResetCamera();
    leftRenderer->ResetCamera();
    rightRenderer->SetActiveCamera(leftRenderer->GetActiveCamera());
    this->gridLayout->addWidget(this->qvtkWidgetLeft);
    this->gridLayout->addWidget(this->qvtkWidgetRight);
    //this->qvtkWidgetRight->GetRenderWindow()->Render();
    this->qvtkWidgetLeft->GetRenderWindow()->Render();
    this->qvtkWidgetRight->GetRenderWindow()->Render();
    
    // Set up action signals and slots
    connect(this->actionExit, SIGNAL(triggered()), this, SLOT(slotExit()));
    this->qvtkWidgetLeft->GetRenderWindow()->AddObserver(vtkCommand::ModifiedEvent, this, &ShareCameraQt::ModifiedHandler);
    this->qvtkWidgetRight->GetRenderWindow()->AddObserver(vtkCommand::ModifiedEvent, this, &ShareCameraQt::ModifiedHandler);
    //this->qvtkWidgetLeft->GetRenderWindow()->AddObserver(vtkCommand::AnyEvent, this, &ShareCameraQt::ModifiedHandler);

}

void ShareCameraQt::ModifiedHandler() 
{
  
  //this->qvtkWidgetRight->GetRenderWindow()->GetRenderers()->GetFirstRenderer()->GetActiveCamera()->ShallowCopy(this->qvtkWidgetLeft->GetRenderWindow()->GetRenderers()->GetFirstRenderer()->GetActiveCamera());
  //this->qvtkWidgetLeft->GetRenderWindow()->Render();
    this->qvtkWidgetRight->GetRenderWindow()->Render();
    this->qvtkWidgetLeft->GetRenderWindow()->Render();
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
       this->qvtkWidgetLeft->GetRenderWindow()->RemoveRenderer(this->qvtkWidgetLeft->GetRenderWindow()->GetRenderers()->GetFirstRenderer());
       this->qvtkWidgetLeft->GetRenderWindow()->AddRenderer(leftRenderer);
      
       this->qvtkWidgetLeft->GetRenderWindow()->RemoveRenderer(this->qvtkWidgetRight->GetRenderWindow()->GetRenderers()->GetFirstRenderer());
       this->qvtkWidgetRight->GetRenderWindow()->AddRenderer(rightRenderer);

       rightRenderer->ResetCamera();
       leftRenderer->ResetCamera();

       rightRenderer->SetActiveCamera(leftRenderer->GetActiveCamera());
       this->qvtkWidgetRight->GetRenderWindow()->Render();
        //this->qvtkWidgetLeft->GetRenderWindow()->AddObserver(vtkCommand::AnyEvent, this, &ShareCameraQt::ModifiedHandler);

}

