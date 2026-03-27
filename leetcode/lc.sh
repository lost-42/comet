#!/bin/sh

# LeetCode题目构建脚本
# 用法: ./lc.sh <题目文件.cpp>
# 假设utils.cpp和题目文件都存在

# 获取输入文件
input_file="$1"

# 获取不带扩展名的文件名
fn=$(basename -s .cpp "$input_file")

# 构建命令
build_cmd="clang++ -std=c++23 -stdlib=libc++ -g -O0 $input_file utils.cpp -o $fn"

echo "构建命令: $build_cmd"
echo ""

# 执行构建
if eval $build_cmd 2>&1; then
    echo "构建成功!"
    echo ""

    # 运行程序
    echo "运行程序:"
    echo "----------------------------------------"
    ./$fn
    echo "----------------------------------------"

    # 清理
    rm $fn
    echo ""
    echo "清理完成"
else
    echo "构建失败!"
    exit 1
fi
