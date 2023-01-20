#include "ubus.h"

#include <libubox/blobmsg_json.h>
#include <syslog.h>

enum
{
    UPTIME,
    __UPTIME_MAX
};

static const struct blobmsg_policy uptime_policy[__UPTIME_MAX] = {
    [UPTIME] = {.name = "uptime", .type = BLOBMSG_TYPE_INT32},
};

static void parse_system_data(struct ubus_request *req, int type,
                              struct blob_attr *msg)
{
    system_data *data = (system_data *)req->priv;
    struct blob_attr *tb[__UPTIME_MAX];

    blobmsg_parse(uptime_policy, __UPTIME_MAX, tb, blob_data(msg), blob_len(msg));

    if (!tb[UPTIME])
    {
        goto err;
    }

    data->valid = true;
    data->system_uptime = blobmsg_get_u64(tb[UPTIME]);
    return;

err:
    syslog(LOG_ERR, "Could not fetch system data from ubus");

    data->valid = false;
    data->system_uptime = 0;
}

int fetch_system_data(struct ubus_context *ctx, system_data *out_data)
{
    const char *const service_name = "system";
    const char *const method_name = "info";
    uint32_t id;
    int err;

    err = ubus_lookup_id(ctx, service_name, &id);
    if (err)
    {
        syslog(LOG_ERR, "Could not find '%s' ubus service", service_name);
        return 1;
    }

    err = ubus_invoke(ctx, id, method_name, NULL, (void *)parse_system_data,
                      out_data, 3000);
    if (err)
    {
        syslog(LOG_ERR, "Could not invoke ubus method");
        return 1;
    }

    return 0;
}