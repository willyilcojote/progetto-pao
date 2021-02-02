#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QMessageBox>

#include <MainWindow.h>
#include <Catalogo.h>
#include <Vector.h>
#include <DeepPtr.h>
#include <BaseNode.h>
#include <Photo.h>
#include <Audio.h>
#include <Video.h>
#include <IOManager.h>
#include <LoadingView.h>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(Katalog::Catalogo &cat, MainWindow &mw, QObject *parent = nullptr);

signals:

public slots:
    void addFile(Katalog::BaseNode *file, std::string destination);
    void saveCatalog();

private:
    Katalog::Catalogo &catalogo;
    MainWindow &mainwindow;

};

#endif // CONTROLLER_H
