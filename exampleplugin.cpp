
#include <QDomDocument>
#include <QFile>
#include <QMultiHash>

#include "exampleworker.h"
#include "exampleplugin.h"

ExamplePlugin::ExamplePlugin(QString complexname) : IHWBrokerPlugin(complexname)
{
    qDebug("ExamplePlugin('%s')", qPrintable(complex_id_));
    //Complex-related config loads here
    QFile config_file("../icfg/complexes/"+complex_id_+"/hardware.xml");
    if (!config_file.exists())
        qFatal("ERROR: Complex hardware configuration file does not exist: '%s'", qPrintable(config_file.fileName()));
    config_file.close();
}

void ExamplePlugin::addConsumer(QString consumer_id)
{
    qDebug("ExamplePlugin::addConsumer('%s')", qPrintable(consumer_id));
    //Consumer-related config loads here

    QFile config_file("../icfg/devices/"+consumer_id+"/tropa.xml");
    if (!config_file.exists())
        qFatal("ERROR: Consumer hardware configuration file does not exist: '%s'", qPrintable(config_file.fileName()));
    config_file.close();
}


void ExamplePlugin::processIndicationImpl(const QVariantList& indication)
{
    qDebug("ExamplePlugin::processIndicationImpl");
    //comes from HWWrapperPLugin.
    //Contains something like: DERP_PACKET, 2, 0x03, 0xdd, 0x14;

    //Send indication to hardware
    foreach(const QVariant &var, indication){
//        sentToExampleHW(var.toInt());
    }
}

void ExamplePlugin::exampleHWReader()
{
    forever {
        int code;
        //code = exampleObtainCode();
        //convert code to event;
        QString consumer = "15kherp";
        QString domain = "BUTNS";
        QString id = "POWAH";
        QVariant value = true;
        emit sendControlEvent(consumer, domain,id, value);  //send to apropriate imitator (consumer) then to logic.
    }
}


extern "C" EXAMPLESHARED_EXPORT ExamplePlugin* createPlugin(QString complexname)
{
    return new ExamplePlugin(complexname);
}
