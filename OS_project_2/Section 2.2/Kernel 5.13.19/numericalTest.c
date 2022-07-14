#include <linux/syscalls.h>
#include <linux/kernel.h>

//STUDENT ID: 0811521 (With leading 0)

int returnValue(int studentId, int a, int b){
	printk("[%d][Ker-5.13.19] syscalltest_returnIndividualValues : [%d][%d]\n", studentId, a, b);
	return 0;
}

int addition(int studentId, int a, int b){
	//	[12345][Ker-5.13.19] syscalltest_addition : [30][20][50]\n
    printk("[%d][Ker-5.13.19] syscalltest_addition : [%d][%d][%d]\n", studentId, a, b, a+b);
    return a+b;
}

int multiplication(int studentId, int a, int b){
	//	[12345][Ker-5.13.19] syscalltest_multiplication : [30][20][600]\n
    printk("[%d][Ker-5.13.19] syscalltest_multiplication : [%d][%d][%d]\n", studentId, a, b, a*b);
    return a*b;
}

int displayDatatypes(int studentId) {
	//	Delete these lines, and insert your code here
	//	This function should return 0, and output in kernel log a message 
	//		of the form:
	//	[12345][Ker-5.13.19] size of unsigned int : [%d] bytes\n
	//	[12345][Ker-5.13.19] size of signed int : [%d] bytes\n
	//	[12345][Ker-5.13.19] size of unsigned long : [%d] bytes\n
	//	[12345][Ker-5.13.19] size of signed long : [%d] bytes\n
	//	[12345][Ker-5.13.19] size of unsigned long long : [%d] bytes\n
	//	[12345][Ker-5.13.19] size of signed long long : [%d] bytes\n
	//	[12345][Ker-5.13.19] size of double : [%d] bytes\n
	//	[12345][Ker-5.13.19] size of char : [%d] bytes\n
	//	where you must get in runtime the value in bytes of the sizes of 
	//		each datatype.
	printk("[%d][Ker-5.13.19] size of unsigned int : [%d] bytes\n", studentId, sizeof(unsigned int));
    printk("[%d][Ker-5.13.19] size of signed int : [%d] bytes\n", studentId, sizeof(int));
    printk("[%d][Ker-5.13.19] size of unsigned long : [%d] bytes\n", studentId, sizeof(unsigned long));
    printk("[%d][Ker-5.13.19] size of signed long : [%d] bytes\n", studentId, sizeof(long));
    printk("[%d][Ker-5.13.19] size of unsigned long long : [%d] bytes\n", studentId, sizeof(unsigned long long));
    printk("[%d][Ker-5.13.19] size of signed long long : [%d] bytes\n", studentId, sizeof(long long));
    printk("[%d][Ker-5.13.19] size of double : [%d] bytes\n", studentId, sizeof(double));
    printk("[%d][Ker-5.13.19] size of char : [%d] bytes\n", studentId, sizeof(char));
    return 0;
}

SYSCALL_DEFINE3(syscalltest_returnIndividualValues, int, studentId, int, a, int, b){
	return returnValue(studentId, a, b);
}

SYSCALL_DEFINE3(syscalltest_addition, int, studentId, int, a, int, b){
	return addition(studentId, a, b);
}

SYSCALL_DEFINE3(syscalltest_multiplication, int, studentId, int, a, int, b){
	return multiplication(studentId, a, b);
}

SYSCALL_DEFINE1(syscalltest_dataTypes, int, studentId){
	return displayDatatypes(studentId);
}

//	Delete these lines, and insert your code here
//	You must create the three system calls:
//	1. syscalltest_addition
//		- Inputs: int studentId, int a, int b, int c
//		- Outputs: return the value obtained by the minimum function above.
// 
//	2. syscalltest_multiplication
//		- Inputs: int studentId, int a, int b, int c
//		- Outputs: return the value obtained by the maximum function above.
// 
//	3. syscalltest_dataTypes
//		- Inputs: int studentId
//		- Outputs: return the value obtained by the displayDatatypes function above.

