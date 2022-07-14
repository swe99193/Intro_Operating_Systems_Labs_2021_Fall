#include <linux/syscalls.h>
#include <linux/kernel.h>

SYSCALL_DEFINE0(syscalltest_helloworld)
{
    printk("[Ker-4.19.148] Hello world from a system call! - OS_Project02!\n");
    return 0;
}

SYSCALL_DEFINE1(syscalltest_echo, int, studentId)
{
    printk("[Ker-4.19.148] My student id is : [%d]\n", studentId);
    return 0;
}
