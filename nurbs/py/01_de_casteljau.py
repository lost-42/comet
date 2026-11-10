"""de Casteljau 算法与 Bezier 曲线可视化（NURBS 学习第 1 步）

运行:
    uv run --no-project --with matplotlib python py/01_de_casteljau.py
输出:
    py/out/01_bezier_casteljau.png
"""

import math
import os

import matplotlib

matplotlib.use("Agg")  # 无 GUI 环境，直接输出图片文件

import matplotlib.pyplot as plt


# ---------- 基础工具 ----------


def lerp(p, q, t):
    return (1-t)*p + t*q


# ---------- de Casteljau 求值 ----------


def de_casteljau(control, t):
    """重复线性插值，求 Bezier 曲线上参数 t 处的点。TODO(2/2): 实现算法本体

    数据结构（点 = [x, y]，两个浮点数的 list）：
      control: list[Point]              控制顶点，如 [[0,0], [1,2.2], [3,2.2], [4,0]]
      返回 (curve_point, levels)，等价于 C++ 的 pair<Point, vector<vector<Point>>>：
        curve_point: Point              曲线上的一个点，即 [x, y]
        levels: list[list[Point]]       三角形，每层是一个点列表
          levels[k][i]   = 第 k 层第 i 个点
          levels[0]      = control 本身
          len(levels[k]) = len(control) - k   （每层少一个点）
          levels[-1]     = [curve_point]      （只含 1 个点的层）
          且 curve_point == levels[-1][0]

    例（4 个控制点，t=0.35，与 notes/01_de_casteljau.md 手算表一致）：
      levels[0]: [[0,0], [1,2.2], [3,2.2], [4,0]]          # 4 个点
      levels[1]: [[0.35,0.77], [1.7,2.2], [3.35,1.43]]     # 3 个点
      levels[2]: [[0.8225,1.2705], [2.2775,1.9305]]        # 2 个点
      levels[3]: [[1.33175,1.5015]]                        # 1 个点 <- 答案

    提示：对每条相邻边做 lerp 得到下一层，直到只剩 1 个点。
    """
    # raise NotImplementedError("TODO(2/2): 实现 de_casteljau")
    n = len(control)
    levels = [control]
    for i in range(1, n):
        
        levels.append(control)


# ---------- Bernstein 定义式（用于对拍验证） ----------


def bernstein_basis(n, i, t):
    """第 i 个 n 次 Bernstein 基函数 C(n,i) t^i (1-t)^(n-i)"""
    return math.comb(n, i) * (t**i) * ((1.0 - t) ** (n - i))


def bezier_bernstein(control, t):
    """按定义式 sum(B_i,n(t) * P_i) 求同一点，与 de Casteljau 对拍。"""
    n = len(control) - 1
    point = [0.0, 0.0]
    for i in range(n + 1):
        coef = bernstein_basis(n, i, t)
        point[0] += coef * control[i][0]
        point[1] += coef * control[i][1]
    return point


def sample_curve(control, num=200):
    """密集采样整条曲线，用于画图。"""
    return [de_casteljau(control, i / (num - 1))[0] for i in range(num)]


# ---------- 主程序 ----------


def main():
    control = [[0.0, 0.0], [1.0, 2.2], [3.0, 2.2], [4.0, 0.0]]  # 三次 Bezier
    t0 = 0.35

    # 1) 控制台打印 de Casteljau 三角形
    point, levels = de_casteljau(control, t0)
    print(f"control points: {control}")
    print(f"t = {t0}")
    for k, lvl in enumerate(levels):
        pts = ", ".join(f"({p[0]:.4f}, {p[1]:.4f})" for p in lvl)
        print(f"  level {k}: {pts}")

    # 2) 与 Bernstein 定义式对拍
    ref = bezier_bernstein(control, t0)
    print(f"de Casteljau: ({point[0]:.6f}, {point[1]:.6f})")
    print(f"Bernstein   : ({ref[0]:.6f}, {ref[1]:.6f})")
    print(f"max diff    : {math.dist(point, ref):.2e}   (expected ~1e-15)")

    # 3) 画图
    curve = sample_curve(control)
    xs = [p[0] for p in curve]
    ys = [p[1] for p in curve]
    cx = [p[0] for p in control]
    cy = [p[1] for p in control]

    fig, axes = plt.subplots(1, 3, figsize=(15.5, 4.6))

    # (a) 曲线 + 控制多边形
    ax = axes[0]
    ax.plot(cx, cy, "o--", color="gray", label="control polygon")
    ax.plot(xs, ys, "b-", lw=2, label="Bezier curve")
    for i, (x, y) in enumerate(control):
        ax.annotate(f"P{i}", (x, y), textcoords="offset points",
                    xytext=(0, 10), ha="center")
    ax.set_title("Bezier curve + control polygon")
    ax.legend(loc="lower right")
    ax.axis("equal")
    ax.grid(True, alpha=0.3)

    # (b) t = t0 处的 de Casteljau 构造三角形
    ax = axes[1]
    ax.plot(xs, ys, color="lightgray", lw=2)
    ax.plot(cx, cy, "o--", color="gray", alpha=0.5)
    colors = ["tab:blue", "tab:orange", "tab:green", "tab:red"]
    for k, lvl in enumerate(levels[:-1]):
        lx = [p[0] for p in lvl]
        ly = [p[1] for p in lvl]
        ax.plot(lx, ly, "o-", lw=2.2 - 0.5 * k, color=colors[k % 4],
                label=f"level {k} ({len(lvl)} pts)")
    ax.plot(point[0], point[1], "r*", ms=18, zorder=5,
            label=f"curve point at t={t0}")
    ax.set_title(f"de Casteljau construction at t={t0}")
    ax.legend(loc="lower right", fontsize=8)
    ax.axis("equal")
    ax.grid(True, alpha=0.3)

    # (c) 三次 Bezier 的 Bernstein 基函数（与 (a) 中的曲线是同一件事的两种写法）
    ax = axes[2]
    ts = [i / 100 for i in range(101)]
    for i in range(4):
        bys = [bernstein_basis(3, i, t) for t in ts]
        ax.plot(ts, bys, lw=2, label=f"$B_{{{i},3}}(t)$")
    ax.set_title("Bernstein basis (degree 3)")
    ax.set_xlabel("t")
    ax.legend()
    ax.grid(True, alpha=0.3)

    fig.tight_layout()
    out_dir = os.path.join(os.path.dirname(os.path.abspath(__file__)), "out")
    os.makedirs(out_dir, exist_ok=True)
    out_path = os.path.join(out_dir, "01_bezier_casteljau.png")
    fig.savefig(out_path, dpi=130)
    print(f"saved: {out_path}")


if __name__ == "__main__":
    main()
