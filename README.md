# Windows ZSTD使用

## 1.重新编译静态库
- 从github下载源代码: [1.5.6版本](https://github.com/facebook/zstd)
- 将源代码解压到指定位置，本文档解答到如下路径:
- D:/source_code/zstd-1.5.6
- 打开CMake.exe
- source_code指向D:/source_code/zstd-1.5.6/build/cmake
- build指向D:/source_code/zstd-1.5.6/build/cmake/build
- 点击Configure进行配置:
- 编译器选择Visual Studio 17 2022
- 平台选择x64
- 如下图所示:
  ![image](https://github.com/user-attachments/assets/0f912c03-9f29-4193-99ee-e9f966b4b381)


  
- 设置CMAKE_INSTALL_PREFIX为D:/gitlab/zstd_1_5_6
- 点击Configure进行配置
- 点击Generate进行生成
- Open Project打开工程
- 生成方式从Debug修改为Release
- 生成平台从x86修改为x64
- 右键点击右侧的”解决方案资源管理器”中的ALL_BUILD生成
- 右键点击右侧的”解决方案资源管理器”中的INSTALL生成以完成编译
- 编译结果会放在D:/gitlab/zstd_1_5_6中;

## 2.配置源码库

- 右键项目 - C/C++ - 常规 - 附加包含目录，填写zstd.h头文件的路径  D:/gitlab/zstd_1_5_6/include
- 右键项目 - 链接器 - 常规 - 附加库目录，填写zstd_static.lib的路径 (可自己修改为libzstd_static.lib)
- 右键项目 - 链接器 - 输入 - 附加依赖项，填写zstd_static.lib库的名字 (如果自己修改为libzstd_static.lib，那此处就填入libzstd_static.lib)
- 把libzstd.dll动态链接库（Linux下后缀名是.so库）放在工程目录下（此项目没有用到，可不用该步骤）
