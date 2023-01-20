#include <stdlib.h>
#include <string.h>
#include <argp.h>

struct arguments
{
    char *devId;
    char *orgId;
    char *typeId;
    char *authT;
    char *configFilePath;
    int daemonize;
};

error_t
parse_opt(int key, char *arg, struct argp_state *state);
