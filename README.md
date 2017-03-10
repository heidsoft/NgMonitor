#工程自动化顺序
第一步 扫描本地目录
autoscan

第二步 重新命名为ac文件
mv configure.scan configure.ac

第三部 编辑configure.ac

第四步configure.ac文件宏说明:
AC_PRERREQ 宏声明文件要求的 autoconf 版本
	AC_INIT 宏用来定义软件的名称和版本等信息。
	其中FULL-PACKAGE-NAME 表示软件的名称；
	VERSION 为软件的版本号； 
	BUG-REPORT-ADDRESS 一般为作者的 E-mail
文件宏顺序说明:
AC_INIT
	测试程序
	测试函数库
	测试头文件
	测试类型定义
	测试结构
	测试编译器特性
	测试库函数
	测试系统调用
AC_OUTPUT

加入下面两个宏在configure.ac文件中
AM_INIT_AUTOMAKE([-Wall -Werror foreign]) 生成make参数
AC_CONFIG_FILES([Makefile])  宏用于生成相应的 Makefile 文件

第五步 这里可能会生成一个 aclocal.m4 ，该文件主要处理本地的宏定义：
aclocal

第六步骤 生成configure文件
autoconf
第七步 生成配置头文件
autoheader
第八步 创建Makefile.am，增加编译目标文件和源文件
Makefile.am
第九步 生成Makefile文件
automake --add-missing
第十步 编译配置
./configure --prefix=$(pwd)/install
第十一步
make && make install


