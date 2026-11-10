# AGENTS.md

本文件是 NURBS 学习项目的**进度同步文件**，供 AI 助手（AGENTS.md-aware agents）在 `nurbs/` 下工作时读取。新会话开始时阅读本文件即可恢复进度；学习有进展时按文末"维护规则"更新。

## 项目目标

理解 CAD 几何内核中的样条 / NURBS 算法（重算法思想，不追求工程落地）：Bezier → B 样条 → NURBS 的求值、节点操作、插值拟合，再到高级话题（求交、圆角、偏移）的思想层面。

背景：C++ CAD 应用层开发，目标是读懂几何内核算法（OpenNURBS 等）。

## 学习路线图

### 第一层：求值（必学）

- [ ] de Casteljau 算法（Bezier 求值）——讲解完成，核心代码待本人手写
- [ ] de Boor 算法（B 样条求值）——内核中最核心的循环
- [ ] 节点向量：重节点与连续性 C0/C1/C2 的关系

### 第二层：曲线变换

- [ ] Boehm 节点插入
- [ ] 节点删除
- [ ] 升阶（degree elevation）
- [ ] Bezier 分解 / 节点细化（Oslo 算法）
- [ ] 验证：以上变换不改变几何形状（只改表示）

### 第三层：插值与拟合

- [ ] 参数化：均匀 / 弦长 / 向心
- [ ] 全局插值（三对角方程组）
- [ ] 最小二乘逼近
- [ ] 曲面：张量积求值、等参线提取

### 第四层：高级话题（了解思想即可，不复现）

- [ ] 曲线/曲面求交（曲面-曲面求交 SSI 为何难）
- [ ] 圆角（rolling ball）
- [ ] 偏移（offset 的奇异与自交问题）
- [ ] 裁剪曲面（trimmed surface）、光顺（fairing）

## 环境与资料

- 原型语言：Python（NumPy + Matplotlib 画图验证，写完即弃，不追求工程化）
- 精读语言：C++（对照 OpenNURBS 源码）
- 书：《The NURBS Book》(Piegl & Tiller) →《Curves and Surfaces for CAGD》(Farin) →《A Practical Guide to Splines》(de Boor)
- 代码：OpenNURBS（`mcneel/opennurbs`，The NURBS Book 的算法编号可与其源码对照阅读）、Geometric Tools / Wild Magic、CGAL
- Python 运行方式：`uv run --no-project python <script>.py`（本机无可用的系统 `python3`）

## 目录结构

- `py/` — Python 原型（画图、验证算法）
- `cpp/` — C++ 实现练习
- `notes/` — 学习笔记（按主题一个 .md）
- 以上目录用到时创建，不必预先搭建

## 进度记录

（最新在上，追加不删除）

### 2026-11-10

- 第 1 步：de Casteljau 算法（Bezier 求值）——讲解与材料完成，**核心代码改为本人手写**（骨架已备）
  - 骨架：[py/01_de_casteljau.py](py/01_de_casteljau.py)（`lerp` / `de_casteljau` 留 TODO；保留三角形打印、Bernstein 对拍、画图作自检）
  - 图：[py/out/01_bezier_casteljau.png](py/out/01_bezier_casteljau.png)（① 曲线+控制多边形 ② t=0.35 构造三角形 ③ 三次 Bernstein 基函数）
  - 笔记：[notes/01_de_casteljau.md](notes/01_de_casteljau.md)
- ⏳ 待办：本人手写 `lerp` + `de_casteljau`，自检通过后勾选路线图
- 下一步：de Boor 算法（B 样条求值）

### 2026-11-09

- 制定四层学习路线，建立本文件
- 下一步：de Casteljau + Matplotlib 画 Bezier 与控制多边形

## 维护规则（给 AI 助手）

学习有进展（学完一节、写了代码、记了笔记、调整了计划）时，更新本文件：

1. 勾选"学习路线图"中已完成的条目；
2. 在"进度记录"顶部追加日期条目（保留历史条目，不删除）；
3. 练习代码放 `py/` 或 `cpp/`，笔记放 `notes/`，并在进度条目中链接到新文件。

其他：

- **核心算法由本人手写**：助手负责讲解直觉与推导、搭 TODO 骨架、写工具代码（画图/对拍/测试）和验收点评；不直接给出 lerp、de Boor、节点插入等核心函数的完整实现。本人卡壳时给提示，不给答案。
- 保持本文件为 nurbs 学习进度的**唯一权威来源**，不要另建平行的进度文件。
- 本目录的学习工作以理解算法为目标，讲解时优先给直觉与推导，而不是工程实现细节。
