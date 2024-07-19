#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/printk.h>
#include <linux/proc_fs.h>
#include <asm/current.h>

#define procfs_name "Mythread_info"
#define BUFSIZE  1024
char buf[BUFSIZE];

static ssize_t Mywrite(struct file *fileptr, const char __user *ubuf, size_t buffer_len, loff_t *offset){
    /*Your code here*/
    int len=buffer_len;
    char tmp_buf[BUFSIZE];
    if (len > BUFSIZE) len = BUFSIZE;
    if (copy_from_user(buf, ubuf, len)){
        return -EFAULT;
    }
    buf[len & (BUFSIZE - 1)] = '\0';
    *offset = len;
    long long unsigned uutime=((current->utime)/100)/1000;
    pthread_mutex_lock(&mutex);
    snprintf(tmp_buf, BUFSIZE, "PID: %d, TID: %s, time: %llu, context switch times: %lu\n", current->tgid, buf, uutime, current->nvcsw+current->nivcsw);
    strlcpy(buf, tmp_buf, BUFSIZE);
    pthread_mutex_unlock(&mutex);
    pr_info("Hello");
    return len;
    /****************/
}


static ssize_t Myread(struct file *fileptr, char __user *ubuf, size_t buffer_len, loff_t *offset){
    /*Your code here*/

    int len=strlen(buf);
    if(*offset > 0 || buffer_len < BUFSIZE){
        pr_info("offset: %lld\n", *offset);
        return 0;
    }
    if(copy_to_user(ubuf,buf,len))
        return -EFAULT;
    *offset = len;
    pr_info("procfile read\n");
    return len;
    /****************/
}

static struct proc_ops Myops = {
    .proc_read = Myread,
    .proc_write = Mywrite,
};

static int My_Kernel_Init(void){
    proc_create(procfs_name, 0644, NULL, &Myops);   
    pr_info("My kernel says Hi");
    return 0;
}

static void My_Kernel_Exit(void){
    pr_info("My kernel says GOODBYE");
}

module_init(My_Kernel_Init);
module_exit(My_Kernel_Exit);

MODULE_LICENSE("GPL");