#include <linux/syscalls.h>
#include <linux/kernel.h>

//STUDENT ID: 0811521 (With leading 0)

int returnValue(int studentId, int a, int b){
	printk("[%d][Ker-4.19.148] syscalltest_returnIndividualValues : [%d][%d]\n", studentId, a, b);
	return 0;
}

int minimum(int studentId, int a, int b, int c){
    //	[12345][Ker-4.19.148] syscalltest_minimum : [30][20][50] - [20]\n
    int min_v;
    if(a<=b)
        if (a<=c)
            min_v = a;
        else
            min_v = c;
    else 
        if (b<=c)
            min_v = b;
        else
            min_v = c;  
	printk("[%d][Ker-4.19.148] syscalltest_minimum : [%d][%d][%d] - [%d]\n", studentId, a, b, c, min_v);

    return min_v;
}

int maximum(int studentId, int a, int b, int c){
	//	Delete these lines, and insert your code here
	//	This function should return the maximum of three values: a,b,c, and output
	//		in kernel log a message of the form:
	//	[12345][Ker-4.19.148] syscalltest_maximum : [30][20][50] - [50]\n

	int max_v;
    if(a<=b)
        if (b<=c)
            max_v = c;
        else
            max_v = b;
    else 
        if (a<=c)
            max_v = c;
        else
            max_v = a;  
	printk("[%d][Ker-4.19.148] syscalltest_maximum : [%d][%d][%d] - [%d]\n", studentId, a, b, c, max_v);
    
    return max_v;
}

int displayDatatypes(int studentId) {
	//	Delete these lines, and insert your code here
	//	This function should return 0, and output in kernel log a message 
	//		of the form:
	//	[12345][Ker-4.19.148] size of unsigned int : [%d] bytes\n
	//	[12345][Ker-4.19.148] size of signed int : [%d] bytes\n
	//	[12345][Ker-4.19.148] size of unsigned long : [%d] bytes\n
	//	[12345][Ker-4.19.148] size of signed long : [%d] bytes\n
	//	[12345][Ker-4.19.148] size of unsigned long long : [%d] bytes\n
	//	[12345][Ker-4.19.148] size of signed long long : [%d] bytes\n
	//	[12345][Ker-4.19.148] size of double : [%d] bytes\n
	//	[12345][Ker-4.19.148] size of char : [%d] bytes\n
	//	where you must get in runtime the value in bytes of the sizes of 
	//		each datatype.

	printk("[%d][Ker-4.19.148] size of unsigned int : [%d] bytes\n", studentId, sizeof(unsigned int));
    printk("[%d][Ker-4.19.148] size of signed int : [%d] bytes\n", studentId, sizeof(int));
    printk("[%d][Ker-4.19.148] size of unsigned long : [%d] bytes\n", studentId, sizeof(unsigned long));
    printk("[%d][Ker-4.19.148] size of signed long : [%d] bytes\n", studentId, sizeof(long));
    printk("[%d][Ker-4.19.148] size of unsigned long long : [%d] bytes\n", studentId, sizeof(unsigned long long));
    printk("[%d][Ker-4.19.148] size of signed long long : [%d] bytes\n", studentId, sizeof(long long));
    printk("[%d][Ker-4.19.148] size of double : [%d] bytes\n", studentId, sizeof(double));
    printk("[%d][Ker-4.19.148] size of char : [%d] bytes\n", studentId, sizeof(char));

    return 0;
}


SYSCALL_DEFINE3(syscalltest_returnIndividualValues, int, studentId, int, a, int, b){
	return returnValue(studentId, a, b);
}

SYSCALL_DEFINE4(syscalltest_minimum, int, studentId, int, a, int, b, int, c){
	return minimum(studentId, a, b, c);
}

SYSCALL_DEFINE4(syscalltest_maximum, int, studentId, int, a, int, b, int, c){
	return maximum(studentId, a, b, c);
}

SYSCALL_DEFINE1(syscalltest_dataTypes, int, studentId){
	return displayDatatypes(studentId);
}


//	Delete these lines, and insert your code here
//	You must create the three system calls:
//	1. syscalltest_minimum
//		- Inputs: int studentId, int a, int b, int c
//		- Outputs: return the value obtained by the minimum function above.
// 
//	2. syscalltest_maximum
//		- Inputs: int studentId, int a, int b, int c
//		- Outputs: return the value obtained by the maximum function above.
// 
//	3. syscalltest_dataTypes
//		- Inputs: int studentId
//		- Outputs: return the value obtained by the displayDatatypes function above.