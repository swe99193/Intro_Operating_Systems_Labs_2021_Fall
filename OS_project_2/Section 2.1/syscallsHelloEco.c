#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

int main()
{
    int studentId = 12345;

    printf("studentId = [%d]\n",studentId);

    // Kernel 4.19.148
    
    printf("\n=== Kernerl 4.19.148 ===\n");

    printf("helloworld : %ld\n", syscall(548));
    printf("echo : %ld\n", syscall(549, studentId));

    // Kernel 5.13.19
    printf("\n=== Kernerl 5.13.19 ===\n");

    printf("helloworld : %ld\n", syscall(554));
    printf("echo : %ld\n", syscall(555, studentId));

    return 0;
}
