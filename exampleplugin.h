#ifndef EXAMPLEPLUGIN_H
#define EXAMPLEPLUGIN_H

#include "example_global.h"

#include <map>

#include <QMap>
#include <QMultiHash>
#include <QPair>
#include <QString>
#include <QThread>
#include <QVector>

#include <hardwaretypes.h>
#include <ihwbrokerplugin.h>


class EXAMPLESHARED_EXPORT ExamplePlugin : public IHWBrokerPlugin {
    Q_OBJECT
public:
    ExamplePlugin(QString complexname);

    //! called from HWBroker
    void addConsumer(QString consumer_id);

    struct ConsumerControlEvent
    {
        QString consumer;
        QString domain;
        QString id;
        QVariant value;
    };
signals:
    void init();    //

protected:
    //! called from HWBroker
    void processIndicationImpl(const QVariantList& indication);

private:
    void exampleHWReader();

};

#endif // EXAMPLEPLUGIN_H
