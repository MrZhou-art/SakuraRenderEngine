#pragma once

#include <iostream>

// -------------------------- 符号导出宏（Windows关键） --------------------------
// 编译 MyMathLib 动态库时：MYMATHLIB_EXPORTS 被定义，用 __declspec(dllexport) 导出符号
// 其他项目使用MyMathLib时：无此宏，用__declspec(dllimport)导入符号
#ifdef _WIN32
    #ifdef MYMATHLIB_EXPORTS
        #define MYMATH_API __declspec(dllexport)
    #else
        #define MYMATH_API __declspec(dllimport)
#endif
#else
    // Linux/macOS无需特殊导出，直接定义为空
    #define MYMATH_API
#endif

// -------------------------- 对外暴露的函数（接口） --------------------------

MYMATH_API int TestFunction();