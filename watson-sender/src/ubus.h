#include <libubus.h>

typedef struct system_data
{
    bool valid;
    int64_t system_uptime;
} system_data;

int fetch_system_data(struct ubus_context *ctx, system_data *out_data);
