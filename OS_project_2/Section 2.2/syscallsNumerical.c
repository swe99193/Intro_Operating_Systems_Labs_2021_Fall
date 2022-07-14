#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

//STUDENT ID: 0811521

int main()
{
    int studentId = 811521;

    int a = 15;
    int b = 43;
    int c = 30;

    printf("a = [%d]\n",a);
    printf("b = [%d]\n",b);
    printf("c = [%d]\n",c);
    printf("studentId = [%d]\n",studentId);
    
    // Kernel 4.19.148
    
    printf("\n=== Kernel 4.19.148 ===\n");

    //Modify system IDs depending on your syscall_64.tbl 
    printf("helloworld : %ld\n", syscall(548));
    printf("echo : %ld\n", syscall(549, studentId));

    printf("returnIndividualValues : %ld\n", syscall(550, studentId, a, b));
    printf("minimum : %ld\n", syscall(551, studentId, a, b, c));
    printf("maximum : %ld\n", syscall(552, studentId, a, b, c));
    printf("dataTypes : %ld\n", syscall(553, studentId));

    // Kernel 5.13.19
    printf("\n=== Kernel 5.13.19 ===\n");

    //Modify system IDs depending on your syscall_64.tbl 
    printf("helloworld : %ld\n", syscall(554));
    printf("echo : %ld\n", syscall(555, studentId));

    printf("returnIndividualValues : %ld\n", syscall(556, studentId, a, b));
    printf("addition : %ld\n", syscall(557, studentId, a, b));
    printf("substraction : %ld\n", syscall(558, studentId, a, b));
    printf("dataTypes : %ld\n", syscall(559, studentId));

    return 0;
}
