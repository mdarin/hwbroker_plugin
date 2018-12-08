#include "exampleplugin.h"
#include <QFile>
#include <QtXml>


ExamplePlugin::ExamplePlugin(IHardwareWrapper* hwwrapper) : IHWWrapperPlugin(hwwrapper)
{
    qDebug("ExamplePlugin()");
    QString device_id(hwwrapper->imitatorName());
    qDebug(qPrintable(device_id));
    QFile config_file("../icfg/devices/"+device_id+"/example.xml"); //Read configuration files
}

void ExamplePlugin::sampleFunction(int derp)
{
    QVariantList params;    //preaparing packet
    params.append(DERP_PACKET); //packet type
    params.append(2);
    params.append(0x03);
    params.append(0xdd);
    params.append(derp);
    ihwwrapper_->sendIndicationParams(TYPE_EXAMPLE, params);    //send packet for example device to HWBroker
}
