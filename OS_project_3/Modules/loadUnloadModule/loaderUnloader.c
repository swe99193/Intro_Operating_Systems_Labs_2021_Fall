#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#define init_module(module_image, len, param_values) syscall(__NR_init_module, module_image, len, param_values)
#define finit_module(fd, param_values, flags) syscall(__NR_finit_module, fd, param_values, flags)
#define delete_module(name, flags) syscall(__NR_delete_module, name, flags)

// Change your data accordingly
// Author: Ricardo Pontaza
// StudentID: 012345 

int main(int argc, char **argv) {
    
    printf("\nThis is a dynamic loader and unloader for a kernel module!\n");

    // Module information
    const char *moduleName = "paramsModule02.ko";
    const char *moduleNameNoExtension = "paramsModule02";
    const char *paramsNew = "studentId=811521";   // Use your StudentID without leading 0
    
    int fd, use_finit;
    size_t image_size;
    struct stat st;
    void *image;

    //Section - Module loading - BEGIN ==============================

    fd = open(moduleName, O_RDONLY);

    printf("Loading module [%s] with parameters [%s]...\n",moduleNameNoExtension,paramsNew);

    fstat(fd, &st);
    image_size = st.st_size;
    image = malloc(image_size);
    read(fd, image, image_size);
    if (init_module(image, image_size, paramsNew) != 0) {
        perror("init_module");
        return EXIT_FAILURE;
    }

    printf("Module is mounted!\n");

    //Section - Module loading - END ====================================

    //  At this point the module is mounted. 
    //  You can check it with $ lsmod | grep <name of module without extension>
    //  You can access its variables in /sys/module/<name of module without extension>/parameters
    
    //  WARNING: IF YOU MODIFY THE VARIABLES WITHOUT FOLLOWING THE CORRECT DATATYPE 
    //      YOUR MODULE WILL GET LOCKED AND YOU MUST FIX THE VARIABLES
    //      AND RESTART YOUR MACHINE.

    printf("\n[Press ENTER to continue]\n");

    getchar();

    //Section - Module unloading - BEGIN ==================================

    printf("Unmounting module...\n");

    if (delete_module(moduleNameNoExtension, O_NONBLOCK) != 0) {
        perror("delete_module");
        return EXIT_FAILURE;
    }

    close(fd);
    printf("Module is unmounted!\n");
    printf("Cleaning...\n");

    free(image);

    //Section - Module unloading - END ======================================

    printf("Done!\n");

    return 0;
}