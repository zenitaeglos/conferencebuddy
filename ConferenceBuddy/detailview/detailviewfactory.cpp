#include "detailviewfactory.h"
#include "tuebix/tuebixdetailview.h"
#include "fosdem/fosdemdetailview.h"


DetailViewFactory::DetailViewFactory(QObject *parent) : QObject(parent)
{

}

DetailView* DetailViewFactory::makeDetailView(QString name)
{
    if (name == "tuebix")
        return new TuebixDetailView();
    else if (name == "fosdem")
        return new FosdemDetailView();

    return new TuebixDetailView();
}
