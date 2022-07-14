#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

#define DRIVER_AUTHOR "Ricardo Pontaza - OS TA 2021" // Replace with your name and student ID
#define DRIVER_DESC   "A sample driver - OS Project 03"


static int studentId = 811521;

static int initialize(void)
{
	printk(KERN_INFO "[%d] : Function [%s] - Hello from OS Project 03!\n", studentId,__func__);
	return 0;
}

static void clean_exit(void){
	printk(KERN_INFO "[%d] : Function [%s] - Unloading module. Goodbye from OS Project 03!\n", studentId,__func__);
}

module_init(initialize);
module_exit(clean_exit);

MODULE_LICENSE("GPL");

MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);