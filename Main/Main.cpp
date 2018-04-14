#include "SystemInclude.h"
#include "Debug.h"
#include "Main.h"

void TestScullReadWrite();
void TestScullIoctl();

void TestScullReadWrite()
{
    FILE *fp0 = NULL;
    char buf[64];

    /*初始化Buf*/
    strcpy(buf, "Scull is char dev!");
    //cout << "buf1: " << buf << endl;

    /*打开设备文件*/
    fp0 = fopen("/dev/scull","r+");
    if (fp0 == NULL)
    {
        cerr << "fopen() failed!" << endl;
        return ;
    }

    /*写入设备*/
    if (fwrite(buf, sizeof(buf), 1, fp0) < 0)
        errstrm << "fwrite() failed!" << endl;
    //errno = 0;

    /*重新定位文件位置（思考没有该指令，会有何后果)*/
    if (fseek(fp0,0,SEEK_SET) < 0)
        errstrm << "fseek() failed!" << endl;

    /*清除Buf*/
    strcpy(buf,"buf is NULL!");
    cout << "buf2: " << buf << endl;

    /*读出设备*/
    fread(buf, sizeof(buf), 1, fp0);
    /*检测结果*/
    cout << "buf3: " << buf << endl;

    fclose(fp0);
}

#include <errno.h>
#include <sys/ioctl.h>

void TestScullIoctl()
{
    int fd;
    int quantum;

    fd = open("/dev/scull",O_RDWR);
    if (fd < 0)
    {
        cerr << "Failed to open()!" << endl;
        return;
    }

    if (ioctl(fd, SCULL_IOCGQUANTUM, &quantum) < 0)
    {
        cerr << "Failed to ioctl()!" << endl;
        return;
    }
    cout << "quantum = " << quantum << endl;
    close(fd);
}

int main(int argc, char *argv[])
{
    DebugFlag debug;
    debug.SetState("main", true);

    dbgstrm << "errno = " << errno << endl;
    TestScullReadWrite();
    dbgstrm << "errno = " << errno << endl;
    TestScullIoctl();
    dbgstrm << "errno = " << errno << endl;

    return 0;
}

