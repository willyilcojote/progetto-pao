#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLayout>
#include <QSizePolicy> //necessaria per la divisione in percentuale dei widget in un layout

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <DeselectableTreeView.h>
#include <QShortcut>
#include <QFileDialog>
#include <GridView.h>
#include <QInputDialog>

#include <BaseNode.h>

class Controller;

typedef Katalog::vector<std::string> PathList;
typedef Katalog::vector<Katalog::DeepPtr<Katalog::BaseNode>> FileList;

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    void setController(Controller *c);
    void updateTree(const Katalog::BaseNode* root);
    void clearTree();
    void showGrid(const FileList& files);

private:
    DeselectableTreeView *catalogView;
    QWidget *screen;
    QHBoxLayout *screenLayout;

    //menu actions
    QAction *SaveAction;

    Controller *controller;

    void addMenus(QLayout *layout);
    void updateTreeRecursive(const Katalog::BaseNode* root, QTreeWidgetItem *itemParent);
    static std::string getFileName(std::string &source);
    std::string getSelectedFilePath() const;
    void setTreeWidgetItemExtras(QTreeWidgetItem *item, Katalog::BaseNode* file);
    static std::string getItemPath(QTreeWidgetItem* item);

signals:
    void addFile(Katalog::BaseNode*, std::string destination);
    void fileCopied(std::string);
    void fileCutted(std::string);
    void filePasted(std::string);
    void fileRemoved(std::string);
    void fileRenamed(std::string, std::string);

private slots:
    /*
     * Abbiamo scelto di usare 3 slot differenti per importare i file, e gestire la creazione
     * per ogni tipo con la view per rendere trasparente la differenza di file al controller
     * Questa scelta arriva dalla possibilità di inserire nuovi tipi di file alla gerarchia e quindi
     * non gestendo le differenze dei file a livello di controller, l'aggiunta di nuovi tipi sarà più veloce
     */
    void addPhoto();
    void addAudio();
    void addVideo();
    void addDirectory();
    void doubleClickOnGridItem(Katalog::BaseNode*);
    void copy();
    void cut();
    void paste();
    void remove();
    void rename();
};

#endif // MAINWINDOW_H
