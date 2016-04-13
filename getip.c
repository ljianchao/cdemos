#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <net/if.h>
#include <arpa/inet.h>
#define ERRORIP "cannot find host ip"
char *ip_search(void)
{
    int sfd, intr;
    struct ifreq buf[16];
    struct ifconf ifc;

    printf("AF_INET=%d\n", AF_INET);
    printf("SOCK_DGRAM=%d\n", SOCK_DGRAM);
    
    sfd = socket (AF_INET, SOCK_DGRAM, 0);
    printf("sfd=%d\n", sfd); 
    if (sfd < 0)
        return ERRORIP;
    int ifc_len_size = sizeof(buf);
    printf("ifc.ifc_len = %d\n", ifc_len_size);
    ifc.ifc_len = ifc_len_size;    
    ifc.ifc_buf = (caddr_t)buf;
    if (ioctl(sfd, SIOCGIFCONF, (char *)&ifc))
        return ERRORIP;
    intr = ifc.ifc_len / sizeof(struct ifreq);
    while (intr-- > 0 && ioctl(sfd, SIOCGIFADDR, (char *)&buf[intr]));
    close(sfd);
    return inet_ntoa(((struct sockaddr_in*)(&buf[intr].ifr_addr))-> sin_addr);
}
int main(void)
{
    printf("%s\n", ip_search());
    return 0;
}
