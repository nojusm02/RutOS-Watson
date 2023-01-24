#include <stdio.h>
#include <signal.h>
#include <memory.h>
#include <stdlib.h>
#include <unistd.h>
#include "inputHandling.h"
#include "iotp_device.h"
#include "deviceHandling.h"

int deviceConfigInit(IoTPConfig **configT, struct arguments arguments)
{
    // IoTPConfig *config = *configT;
    int rc = 0;

    rc = IoTPConfig_create(configT, arguments.configFilePath);

    if (!arguments.configFilePath)
    {
        IoTPConfig_setProperty(*configT, "identity.orgId", arguments.orgId);
        IoTPConfig_setProperty(*configT, "identity.typeId", arguments.typeId);
        IoTPConfig_setProperty(*configT, "identity.deviceId", arguments.devId);
        IoTPConfig_setProperty(*configT, "auth.token", arguments.authT);
    }

    if (rc)
    {
        fprintf(stderr, "ERROR: Failed to configure IoTP device: rc=%d\n", rc);
    }
    return rc;
}
