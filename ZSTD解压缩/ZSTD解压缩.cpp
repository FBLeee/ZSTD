// ZSTD解压缩.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "util.h"
#include <iomanip>  // std::setw, std::setfill
#include <sstream>  //geline、istringstream
#include <queue>


unsigned char hexStringToByte(const std::string& byteStr) {
    unsigned int byte;
    std::stringstream ss;
    ss << std::hex << byteStr;
    ss >> byte;

    if (ss.fail() || !ss.eof()) {
        throw std::invalid_argument("无效的十六进制字节: " + byteStr);
    }

    return static_cast<unsigned char>(byte);
}


int main()
{
//字符串zstd压缩
#if 0
    std::string input_org = "Hello World!";
    std::string out_org = "";
    util::Util::CompressString(input_org, out_org, 3);
    for (unsigned char p : out_org) {
        std::cout << std::hex << static_cast<unsigned int>(p) << " ";
    }
    std::cout <<std::endl;
#endif

//对vector数组ZSTD压缩
#if 0
    
    // 使用字节数组表示报文
    std::vector<unsigned char> input = { 
        0x48,0x65,0x6C,0x6C,0x6F,0x20,0x57,0x6F,0x72,0x6C,0x64,0x21
    };
    std::string out = "";


    //ZSTD压缩！
    util::Util::CompressString_vec(input, out);

    int count = 0;
    // 输出压缩后的结果，按十六进制显示
    for (unsigned char p : out) {
        if (count && count % 16 == 0) {
            std::cout << "\n";
        }
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<unsigned int>(p) << " ";
        count++;
    }
    std::cout << std::endl;


#endif


//对vector数组ZSTD解压
#if 0
    std::cout << "------------------------------------------" << std::endl;
    std::string out = "";
   
    std::vector<unsigned char> needToDecode = {

        0x28,0xB5,0x2F,0xFD,0x20,0x0C,0x61,0x00,0x00,0x48,0x65,0x6C,0x6C,0x6F,0x20,0x57,0x6F,0x72,0x6C,0x64,0x21
    };

    //ZSTD解压
    // 将 std::string 转换为 std::vector<unsigned char>
    int count = 0;
    std::vector<unsigned char> vec(needToDecode.begin(), needToDecode.end());
    util::Util::DecompressString_vec(vec, out);
    // 输出解压后的结果，按十六进制显示
    for (unsigned char p : out) {
        if (count && count % 16 == 0) {
            std::cout << "\n";
        }
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<unsigned int>(p) << " ";
        count++;
    }
    std::cout << std::endl;

#endif


//对报文数据先进行0xFF异或后再ZSTD解压
#if 1
    std::string input_str;
    std::string out_str;
    std::vector<unsigned char> zstdDecode;

    /*
    输入格式如下：
    D7 4A D0 02 DF F3 9E FF FF B7 9A 93 93 90 DF A8
    90 8D 93 9B DE
    
    */
    std::cout << "请输入字节（格式：D7 4A D0 ...），输入空行结束:\n";
    while (std::getline(std::cin, input_str) && !input_str.empty()) {
        //将整行数据当做一个流
        std::istringstream iss(input_str);
        std::string byteStr;

        // 逐字节读取，并转换为unsigned char
        while (iss >> byteStr) {
            try {
                unsigned char before_ZSTD = hexStringToByte(byteStr) ^ 0xFF;
                zstdDecode.push_back(before_ZSTD);
            }
            catch (const std::invalid_argument& e) {
                std::cerr << e.what() << std::endl;
            }
        }

    }

    //ZSTD解压
    int zstd_count = 0;
    util::Util::DecompressString_vec(zstdDecode, out_str);
    

    // 输出结果
    std::cout << "修改后的字节:\n";
    for (const unsigned char& b : out_str) {
        if (zstd_count && zstd_count % 16 == 0) {
            std::cout << "\n";
        }
        //使其以大写形式显示。
        std::cout << std::hex << std::uppercase << std::setw(2) << std::setfill('0')<< static_cast<unsigned int>(b) << " ";
        //控制显示
        zstd_count++;
    }
    std::cout << std::dec << std::endl;
#endif


}
