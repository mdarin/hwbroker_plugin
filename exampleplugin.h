#ifndef EXAMPLEPLUGIN_H
#define EXAMPLEPLUGIN_H

#include "example_global.h"

#include <QVector>
//#include <QMap>

#include <ihwwrapperplugin.h>

class OORange {};

class EXAMPLESHARED_EXPORT ExamplePlugin : public IHWWrapperPlugin {
public:
    ExamplePlugin(IHardwareWrapper* hwwrapper);
    /**
     * @brief Functiomn callsed from wrapper it sends someting to HWBroker
     * @param derp some parameter
     */
    void sampleFunction(int derp);

private:

};

#endif // EXAMPLEPLUGIN_H
