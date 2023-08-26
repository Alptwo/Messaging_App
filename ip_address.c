#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>

int main() {
    char hostbuffer[256];
    char *ip_address;
    struct hostent *host_entry;

    // Yerel makinenin adını al
    if (gethostname(hostbuffer, sizeof(hostbuffer)) == -1) {
        perror("gethostname");
        return 1;
    }

    // Yerel makinenin IP adresini al
    host_entry = gethostbyname(hostbuffer);
    if (host_entry == NULL) {
        perror("gethostbyname");
        return 1;
    }

    // İlk IP adresini al
    ip_address = inet_ntoa(*((struct in_addr*)host_entry->h_addr_list[0]));

    printf("Yerel IP Adresi: %s\n", ip_address);

    return 0;
}
