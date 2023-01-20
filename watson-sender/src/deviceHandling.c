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
    IoTPConfig *config = *configT;
    int rc = 0;
    if (strcmp(arguments.configFilePath, "-") == 0)
    {
        rc = IoTPConfig_create(&config, NULL);
        if (rc != 0)
        {
            fprintf(stderr, "ERROR: Failed to configure IoTP device: rc=%d\n", rc);
            return 1;
        }
        IoTPConfig_setProperty(config, "identity.orgId", arguments.args[0]);
        IoTPConfig_setProperty(config, "identity.typeId", arguments.args[1]);
        IoTPConfig_setProperty(config, "identity.deviceId", arguments.args[2]);
        IoTPConfig_setProperty(config, "auth.token", arguments.args[3]);
        *configT = config;
    }
    else
    {

        rc = IoTPConfig_create(&config, arguments.configFilePath);
        if (rc != 0)
        {
            fprintf(stderr, "ERROR: Failed to configure IoTP device: rc=%d\n", rc);
            return 1;
        }
        *configT = config;
    }
    return 0;
}