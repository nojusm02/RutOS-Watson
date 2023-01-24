#include <stdlib.h>
#include <string.h>
#include <argp.h>
#include <string.h>
#include "inputHandling.h"

/* Parse a single option. */
error_t
parse_opt(int key, char *arg, struct argp_state *state)
{

    /* Get the input argument from argp_parse, which we
       know is a pointer to our arguments structure. */
    struct arguments *arguments = state->input;

    switch (key)
    {
    case 'c':
        arguments->configFilePath = arg;
        break;
    case 'o':
        // arguments->orgId = arg;
        strncpy(arguments->orgId, arg, 29);
        ARGP_KEY_ARG;
        break;
    case 't':
        arguments->typeId = arg;
        ARGP_KEY_ARG;
        break;
    case 'd':
        arguments->devId = arg;
        ARGP_KEY_ARG;
        break;
    case 'a':
        arguments->authT = arg;
        ARGP_KEY_ARG;
        break;
    case 'b':
        arguments->daemonize = 1;
        break;

    case ARGP_KEY_END:

        if (arguments->configFilePath == NULL)
        {
            if (arguments->devId == NULL || arguments->orgId == NULL || arguments->typeId == NULL || arguments->authT == NULL)
            {
                argp_usage(state);
            }
        }
        else if (arguments->configFilePath != NULL)
        {
            arguments->devId = "";
            strncpy(arguments->orgId, "", 29);
            arguments->typeId = "";
            arguments->authT = "";
        }
        break;

    default:
        return ARGP_ERR_UNKNOWN;
    }
    return 0;
}
