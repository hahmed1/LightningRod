#ifndef NETWORK_H
#define NETWORK_H

void net_initialize();
char *net_get(char *url, size_t *size);
void net_cleanup();


#endif
