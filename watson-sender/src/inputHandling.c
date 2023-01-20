#include <stdlib.h>
#include <string.h>
#include <argp.h>
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
        arguments->args[0] = arg;
        ARGP_KEY_ARG;
        break;
    case 't':
        arguments->args[1] = arg;
        ARGP_KEY_ARG;
        break;
    case 'd':
        arguments->args[2] = arg;
        ARGP_KEY_ARG;
        break;
    case 'a':
        arguments->args[3] = arg;
        ARGP_KEY_ARG;
        break;
    case 'b':
        arguments->daemonize = 1;
        break;

    case ARGP_KEY_END:
        // tvarkyt čia
        if (state->arg_num >= 4)
            // argp_usage(state);
            break;

        if ((strcmp(arguments->configFilePath, "-") == 0))
        {
            for (int i = 0; i < 4; i++)
            {
                if (arguments->args[i] == '\0')
                {
                    argp_usage(state);
                }
            }
            break;
        }
        else if (strcmp(arguments->configFilePath, "-") != 0)
        {
            for (int i = 0; i < 4; i++)
            {
                arguments->args[i] = "bus naudojamas configui";
            }
        }
        break;

    default:
        return ARGP_ERR_UNKNOWN;
    }
    return 0;
}
