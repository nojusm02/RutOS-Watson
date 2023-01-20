#include <stdlib.h>
#include <string.h>
#include <argp.h>

struct arguments
{
    char *args[4]; /* arg1 & arg2 */
    char *configFilePath;
    int daemonize;
};

error_t
parse_opt(int key, char *arg, struct argp_state *state);
