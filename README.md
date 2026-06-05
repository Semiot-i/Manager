# 📚 StudentInfoSystem - 学生信息管理系统

> 基于 C11 标准的学生信息管理系统，采用三层架构设计

---

## 📊 项目概览

| 项目 | 说明 |
|:----:|:----|
| 📁 源文件数 | 17 个 |
| 🧩 架构层次 | 3 层（app/core/utils） |
| 📋 C 标准 | C11 |
| 🔨 构建工具 | CMake + Ninja |
| 🖥️ 开发环境 | Windows + CLion |
| 🎨 UI 框架 | GTK4（可选） |

---

## 🏗️ 项目架构

本项目采用**三层架构**设计，清晰分离关注点：

```
┌─────────────────────────────────────────┐
│          应用层 (app/)                   │
│  负责用户界面和交互逻辑                   │
├─────────────────────────────────────────┤
│        核心业务层 (core/)                │
│  负责数据处理和业务逻辑                   │
├─────────────────────────────────────────┤
│          工具层 (utils/)                 │
│  提供通用工具函数                         │
└─────────────────────────────────────────┘
```

---

## 📂 项目目录结构

```
StudentInfoSystem/
│
├── 📄 CMakeLists.txt                    # CMake 构建配置
├── 📄 Framework.txt                     # 项目框架说明
├── 📄 README.md                         # 项目文档
│
├── src/                                 # 源代码目录
│   ├── 📄 main.c                        # 程序入口（控制台测试）
│   │
│   ├── app/                             # 应用层（GTK4 UI界面）
│   │   ├── app_window.c/h              #    主窗口管理
│   │   ├── file_browser.c/h            #    文件浏览界面
│   │   ├── student_editor.c/h          #    学生信息编辑界面
│   │   └── settings.c/h                #    设置界面
│   │
│   ├── core/                            # 核心业务层
│   │   ├── student_list.c/h            #    学生链表管理（数据结构）
│   │   ├── student_process.c/h         #    学生节点操作（增删改）
│   │   ├── file_manager.c/h            #    文件读写操作
│   │   └── command.c/h                 #    命令模式（撤销/重做）
│   │
│   ├── utils/                           # 工具层
│   │   ├── config.c/h                  #    配置文件管理
│   │   ├── validator.c/h               #    数据验证
│   │   └── thread_pool.c/h             #    线程池（预留）
│   │
│   └── include/                         # 公共头文件
│       └── common.h                     #    通用头文件（标准库包含）
│
├── resources/                           # UI资源文件
│   └── style.css                        #    GTK4 样式表
│
└── data/                                # 数据文件存储
```

---

## 🔗 模块依赖关系图

```
                    ┌─────────────┐
                    │   main.c    │  ← 程序入口（当前为控制台测试）
                    └──────┬──────┘
                           │
          ┌────────────────┼────────────────┐
          │                │                │
          ▼                ▼                ▼
  ┌──────────────┐ ┌──────────────┐ ┌──────────────┐
  │    app/      │ │    core/     │ │   utils/     │
  │  (应用层)     │ │ (核心业务层) │  │  (工具层)    │
  └──────┬───────┘ └──────┬───────┘ └──────┬───────┘
         │                │                │
         │                ▼                │
         │        ┌──────────────┐         │
         └───────►│  common.h    │◄────────┘
                  └──────────────┘
```

**依赖说明：**
- 🟦 **app/** → 依赖 core/ 和 utils/，提供 GTK4 图形界面
- 🟩 **core/** → 依赖 common.h，实现核心业务逻辑
- 🟨 **utils/** → 独立工具模块，被其他层调用
- ⬜ **include/common.h** → 全局共享的头文件（包含 stdio.h、stdlib.h 等）

---

## 📦 模块详细说明

### 1️⃣ 应用层 (app/) - GTK4 图形界面

> **注意**：当前 main.c 使用控制台模式进行测试，app/ 目录下的 GTK4 界面代码待集成。

- **app_window.c/h** - 主窗口管理
  - 创建和管理 GTK4 主窗口
  - 处理窗口事件和信号
  
- **file_browser.c/h** - 文件浏览界面
  - 文件选择对话框
  - 文件列表显示和导航
  
- **student_editor.c/h** - 学生信息编辑界面
  - 添加/修改学生信息的表单
  - 输入验证和错误提示
  
- **settings.c/h** - 设置界面
  - 系统配置管理
  - 用户偏好设置保存

---

### 2️⃣ 核心业务层 (core/) - 数据处理

- **student_list.c/h** - 学生链表管理
  - `StudentNode` 链表节点结构定义
  - `StudentInfo` 学生信息结构体
  - 链表初始化、遍历、释放
  - 创建新节点 `createNode()`
  
- **student_process.c/h** - 学生节点操作
  - 尾部添加节点 `addNode_Tail()`
  - 按位置删除 `deleteByPos()`
  - 按位置/学号修改 `modifyByPos()` / `modifyById()`
  
- **file_manager.c/h** - 文件读写操作
  - 学生数据持久化到文件
  - 从文件加载学生列表
  - 文件格式处理（待实现）
  
- **command.c/h** - 命令模式
  - 支持撤销/重做功能
  - 命令历史记录管理（待实现）

---

### 3️⃣ 工具层 (utils/) - 通用工具

- **config.c/h** - 配置文件管理
  - 读取/写入 INI 格式配置
  - 配置项验证和默认值处理
  
- **validator.c/h** - 数据验证
  - 学号、姓名、电话等字段校验
  - 日期格式检查（YYYY-MM-DD）
  - 输入数据合法性验证
  
- **thread_pool.c/h** - 线程池
  - 异步任务处理框架（预留）
  - 多线程并发支持（待实现）

---

## ⚙️ 构建与运行

### 前置要求

- **编译器**: GCC 或 MSVC
- **CMake**: ≥ 3.10
- **构建工具**: Ninja 或 Make
- **GTK4**: （可选，如需图形界面）
  - Windows: 通过 MSYS64 安装 `mingw-w64-x86_64-gtk4`
  - Linux: `sudo apt install libgtk-4-dev`

### 步骤 1：配置 CMake

```bash
mkdir build && cd build
cmake -G Ninja ..
```

**CMake 执行的操作：**
- ✅ 设置 C11 标准
- ✅ 查找 GTK4 库（如果启用）
- ✅ 配置头文件搜索路径：`src/include`
- ✅ 生成构建文件

### 步骤 2：编译项目

```bash
ninja
# 或使用 make
make
```

**编译过程：**
```
所有 .c 文件 ──► 编译器 (gcc/msvc) ──► for_review.exe
```

### 步骤 3：运行程序

```bash
./for_review
```

当前程序以**控制台模式**运行，提供以下功能：
1. 添加学生信息
2. 删除学生
3. 修改学生信息
4. 查询学生
5. 列出所有学生
6. 保存到文件
7. 从文件加载

---

## 🔧 开发注意事项

### 头文件包含规范

在 CMake 项目中，必须显式配置头文件搜索路径：

```cmake
include_directories(${CMAKE_SOURCE_DIR}/src/include)
```

跨目录包含头文件时使用相对路径：
```c
// 在 src/core/student_list.c 中
#include "../include/common.h"  // ✅ 正确
#include "common.h"             // ❌ 错误（未配置路径时）
```

### Windows 平台兼容性

使用 Visual Studio 编译器时，需要定义宏以禁用安全警告：

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
```

或在 CMakeLists.txt 中添加：
```cmake
add_definitions(-D_CRT_SECURE_NO_WARNINGS)
```

### GTK4 依赖配置（Windows）

如果使用 GTK4，需要在 Windows 上安装 MSYS64 并配置 pkg-config：

```cmake
# 手动指定 pkg-config 路径
set(PKG_CONFIG_EXECUTABLE "C:/msys64/mingw64/bin/pkg-config.exe" CACHE FILEPATH "pkg-config executable")
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)
```

---

## 📝 当前状态与待办事项

### ✅ 已完成
- [x] 项目三层架构搭建
- [x] 学生链表数据结构实现
- [x] 基本的增删改查功能
- [x] CMake 构建配置
- [x] 控制台测试界面

### 🚧 进行中
- [ ] 文件读写功能完善
- [ ] 数据验证模块实现
- [ ] 配置文件管理

### 📋 待开发
- [ ] GTK4 图形界面集成
- [ ] 命令模式（撤销/重做）
- [ ] 线程池实现
- [ ] 日志记录功能
- [ ] 单元测试

---

## 📚 技术栈

- **语言**: C (C11 标准)
- **构建系统**: CMake + Ninja
- **UI 框架**: GTK4（可选）
- **IDE**: CLion
- **版本控制**: Git

---

*最后更新：2026/6/6*
