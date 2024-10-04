//
// -*- coding: utf-8-unix; -*-
//  Copyright (c) 2020 Tencent, Inc.
//     All rights reserved.
//
// Date:   2020/11/30 13:45
// File:   util.h
// Desc:
//

#pragma once

#include <string>
#include <vector>

namespace util {

const int DEFAULTCOMPRESSLEVEL = 3;

class Util {
 public:

  static int CompressString_vec(const std::vector<unsigned char>& src, std::string& dst,
                               int compressionlevel = DEFAULTCOMPRESSLEVEL);

  static int DecompressString_vec(const std::vector<unsigned char>& src, std::string& dst);
  static int StreamDecompressString_vec(const std::vector<unsigned char>& src, std::string& dst,
                                  int compressionlevel = DEFAULTCOMPRESSLEVEL);






  // if return code not 0 is error
  static int CompressString(const std::string& src, std::string& dst,
                            int compressionlevel = DEFAULTCOMPRESSLEVEL);

  // if return code not 0 is error
  static int DecompressString(const std::string& src, std::string& dst);

  // if return code not 0 is error
  static int StreamDecompressString(const std::string& src, std::string& dst,
                                    int compressionlevel = DEFAULTCOMPRESSLEVEL);

  // if return code not 0 is error
  static int StreamCompressString(const std::string& src, std::string& dst,
                                  int compressionlevel = DEFAULTCOMPRESSLEVEL);
};

}  // namespace util
