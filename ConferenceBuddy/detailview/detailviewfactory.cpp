#include "detailviewfactory.h"
#include "tuebix/tuebixdetailview.h"


DetailViewFactory::DetailViewFactory(QObject *parent) : QObject(parent)
{

}

DetailView* DetailViewFactory::makeDetailView(QString name)
{
    if (name == "tuebix")
        return new TuebixDetailView();

    return new TuebixDetailView();
}
