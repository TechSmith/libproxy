#include <stdlib.h>
#include <string.h>

#include <misc.h>
#include <proxy_factory.h>

PXConfig *get_config_cb(pxProxyFactory *self)
{
	char *proxy = getenv("http_proxy");
	if (!proxy)  return NULL;
	PXConfig *config = malloc(sizeof(PXConfig));
	if (!config) return NULL;
	config->url = px_strdup(proxy);
	if (!config->url) { free(config); return NULL; }
	config->ignore = px_strdup(""); // TODO: Make this pay attention to 'no_proxy' later
	if (!config->ignore) { free(config->url); free(config); return NULL; }
	return config;
}

bool on_proxy_factory_instantiate(pxProxyFactory *self)
{
	return px_proxy_factory_config_set(self, PX_CONFIG_BACKEND_ENVVAR, get_config_cb);
}

void on_proxy_factory_destantiate(pxProxyFactory *self)
{
	px_proxy_factory_config_set(self, PX_CONFIG_BACKEND_ENVVAR, NULL);
}