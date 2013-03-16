#ifndef ShareCameraQt_H
#define ShareCameraQt_H

#include <QMainWindow>
#include "ui_ShareCameraQt.h"

class ShareCameraQt : public QMainWindow, public Ui::ShareCameraQt
{
  Q_OBJECT
public:

  // Constructor/Destructor
  ShareCameraQt(); 
  ~ShareCameraQt() {};

public slots:

  virtual void slotExit();

protected:
   void ModifiedHandler();
private slots:
   void on_pushButton_clicked();
   void on_pushButton_2_clicked();
};

#endif
