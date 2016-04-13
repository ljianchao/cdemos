#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <net/if.h>
#include <arpa/inet.h>

int main()
{
    int i = 0;
    int sockfd;
    struct ifconf ifconf;
    unsigned char buf[512];
    struct ifreq * ifreq;
    
    //初始化ifconf
    ifconf.ifc_len = 512;
    ifconf.ifc_buf = buf;
    
    printf("AF_INET = %d, SOCK_DGRAM = %d.\n", AF_INET, SOCK_DGRAM);
    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        printf("error: socket is not connected.\n");
        return -1;
    }
        
    //获取所有接口信息
    ioctl(sockfd, SIOCGIFCONF, &ifconf);
    
    ifreq = (struct ifreq*)buf;
    printf("buf addr is %p\n", ifreq);
    int ifreq_size = sizeof(struct ifreq);
    printf("ifreq_size = %d\n", ifreq_size);
    int buf_count = ifconf.ifc_len/ifreq_size;
    printf("buf_count = %d.\n", buf_count);
    
    for(i = buf_count; i > 0; i--)
    {
        printf("buf addr is %p\n", ifreq);
        printf("name=[%s]\n", ifreq->ifr_name);
        printf("local addr = [%s]\n",
                inet_ntoa(((struct sockaddr_in*)&(ifreq->ifr_addr))->sin_addr));
        ifreq++;
    }
    
    return 0;
}