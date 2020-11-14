#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"

#define FONTSIZE 10
int PrintMenuOS()
{
    int i, j;
    char data_M[FONTSIZE][FONTSIZE] =
    {
        "          ",
        "  *    *  ",
        " ***  *** ",
        " * *  * * ",
        " * *  * * ",
        " *  **  * ",
        " *      * ",
        " *      * ",
        " *      * ",
        "          "
    };
    char data_e[FONTSIZE][FONTSIZE] =
    {
        "          ",
        "          ",
        "    **    ",
        "   *  *   ",
        "  *    *  ",
        "  ******  ",
        "  *       ",
        "   *      ",
        "    ***   ",
        "          "
    };
    char data_n[FONTSIZE][FONTSIZE] =
    {
        "          ",
        "          ",
        "    **    ",
        "   *  *   ",
        "  *    *  ",
        "  *    *  ",
        "  *    *  ",
        "  *    *  ",
        "  *    *  ",
        "          "
    };
    char data_u[FONTSIZE][FONTSIZE] =
    {
        "          ",
        "          ",
        "  *    *  ",
        "  *    *  ",
        "  *    *  ",
        "  *    *  ",
        "  *    *  ",
        "   *  **  ",
        "    **  * ",
        "          "
    };
    char data_O[FONTSIZE][FONTSIZE] =
    {
        "          ",
        "   ****   ",
        "  *    *  ",
        " *      * ",
        " *      * ",
        " *      * ",
        " *      * ",
        "  *    *  ",
        "   ****   ",
        "          "
    };
    char data_S[FONTSIZE][FONTSIZE] =
    {
        "          ",
        "    ****  ",
        "   **     ",
        "  **      ",
        "   ***    ",
        "     **   ",
        "      **  ",
        "     **   ",
        "  ****    ",
        "          "
    };

    for(i=0; i<FONTSIZE; i++)
    {
        for(j=0; j<FONTSIZE; j++)
        {
            printf("%c", data_M[i][j]);
        }
        for(j=0; j<FONTSIZE; j++)
        {
            printf("%c", data_e[i][j]);
        }
        for(j=0; j<FONTSIZE; j++)
        {
            printf("%c", data_n[i][j]);
        }
        for(j=0; j<FONTSIZE; j++)
        {
            printf("%c", data_u[i][j]);
        }
        for(j=0; j<FONTSIZE; j++)
        {
            printf("%c", data_O[i][j]);
        }
        for(j=0; j<FONTSIZE; j++)
        {
            printf("%c", data_S[i][j]);
        }
        printf("\n");
    }
    return 0;
}


int Quit(int argc, char *argv[])
{
    // 通过int ExecuteMenu()中增加if(p->handler == Quit){return 0;}出循环
    /* add XXX clean ops */
}

int Time(int argc, char *argv[])
{
    time_t tt;
    struct tm *t;
    tt = time(NULL);
    t = localtime(&tt);
    printf("time:%d:%d:%d:%d:%d:%d\n",t->tm_year+1900, t->tm_mon, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
    return 0;
}

int TimeAsm(int argc, char *argv[])
{
    time_t tt;
    struct tm *t;
    asm volatile(
        "mov $0,%%ebx\n\t"
        "mov $0xd,%%eax\n\t"
        "int $0x80\n\t"
        "mov %%eax,%0\n\t"
        : "=m" (tt)
    );
    t = localtime(&tt);
    printf("time:%d:%d:%d:%d:%d:%d\n",t->tm_year+1900, t->tm_mon, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
    return 0;
}
int hello(int argc, char *argv[]){
	printf("hello 20209313\n");
    return 0;
}

int main()
{
    PrintMenuOS();
    SetPrompt("MenuOS>>");
    MenuConfig("version","MenuOS V1.0(Based on Linux 3.18.6)",NULL);
    MenuConfig("quit","Quit from MenuOS",Quit);
    MenuConfig("time","Show System Time",Time);
    MenuConfig("time-asm","Show System Time(asm)",TimeAsm);
    MenuConfig("hello","bring happiness to you",hello);
    ExecuteMenu();
}

git config --global user.name "Ulysiss"
git config --global user.email "745047172@qq.com"
https://github.com/Ulysiss
git remote add origin https://github.com/Ulysiss/Linux-homework.git

#初始化文件夹
// git init
1、新建一个文件夹（eg:gittest）;邮件此文件夹选择通过Code打开。
2、此时选择源代码管理器，点击初始化存储库或者打开终端输入git init即可将该文件夹变成一个可管理的仓库。

#设置全局配置
git config --global user.name "your name" #配置密码账号。
git config --global user.email "your email" #配置密码账号。
git remote add origin https://github.com/youtname/仓库名.git #添加远程仓库（账号/密码），使用时必须先创建
git config --global credential.helper store   //配置密码账号。在Git Bash输入这个命令就可以了

#使用：暂存,放到缓存区；提交，放到本地仓库；push 推送到远程仓库
git add "yourfile" // 点击 + 相当于git add file
git commit -m "说明" // 点击对号；等于git commit -m "备注信息"；右边的箭头输入需要备注的信息。然后按 ctrl+enter 确定。
git pull origin master // 拉取代码从云端到本地(提交代码的时候，一定要先拉取代码；不然就会造成冲突)
git push origin master// 推送本地仓库至服务器
git clone https://github.com/youtname/your repository.git     //克隆项目

#其他命令
git init #创建仓库
git add a.txt #暂存a.txt
git commit -m “说明” #提交暂存至仓库
git checkout – a.txt #使用暂存/仓库中的a.txt覆盖工作区（有优先级）。
rm a.txt #删除工作区的a.txt
cat a.txt #查看工作区a.txt
git reset --hard HEAD^ #回退一个版本
git log #查看仓库历史版本，后面添加–pretty=oneline可以简化显示
git reflog #查看所有版本，包括回退之前的版本
git status #查看文件状态

history #查看历史输入命令
pwd #查看当前工作区所在位置

