# Student Information System

学生信息管理系统 - 基于C语言的命令行应用

## 项目结构

```
StudentInfoSystem/
├── src/
│   ├── main.c                    # 程序入口
│   ├── app/                      # 交互层
│   │   ├── app_window.c/h        # 主窗口与菜单
│   │   ├── file_browser.c/h      # 文件浏览界面
│   │   └── student_editor.c/h    # 学生信息显示与编辑
│   ├── core/                     # 核心业务层
│   │   ├── student_process.c/h   # 学生数据操作
│   │   ├── student_list.c/h      # 链表管理与遍历
│   │   ├── file_manager.c/h      # 文件读写操作
│   │   └── command.c/h           # 操作封装接口
│   └── include/                  # 公共头文件
│       └── common.h
├── data/                         # 数据文件存储
└── CMakeLists.txt                # CMake构建配置
```

## 功能特性

- **添加学生** - 录入学生基本信息
- **删除学生** - 按位置或学号删除
- **修改学生** - 支持修改单个字段或全部信息
- **查询学生** - 按位置或学号查询
- **列表显示** - 表格形式展示所有学生信息
- **文件操作** - 支持从文件加载和保存到文件

## 编译运行

### 依赖要求
- CMake 3.10+
- C编译器 (GCC/MinGW)

### 编译步骤

```bash
# 配置项目
cmake -B build -S .

# 构建项目
cmake --build build
```

### 运行程序

```bash
./build/StudentInfoSystem.exe
```

## 使用说明

启动程序后，根据菜单提示选择操作：

```
========================================
       Student Information System
========================================
1. Add Student          # 添加学生
2. Delete Student       # 删除学生
3. Modify Student       # 修改学生
4. Query Student        # 查询学生
5. List All Students    # 列出所有学生
6. Load from File       # 从文件加载
7. Save to File         # 保存到文件
0. Exit                 # 退出系统
========================================
```

## 数据格式

学生信息包含以下字段：
- 学号 (ID)
- 宿舍号 (Room Number)
- 姓名 (Name)
- 性别 (Sex)
- 班级 (Class)
- 生日 (Birth)
- 家庭地址 (Home)
- 电话 (Phone)

## 技术栈

- **语言**: C11
- **构建工具**: CMake
- **数据结构**: 链表
- **架构**: 两层架构 (app/core)

## 许可证

本项目仅供学习使用。
