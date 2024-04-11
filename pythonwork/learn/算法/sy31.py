#陈艺铭
import random
import time
import sys
#填方格
def chessboard_cover(board, tr, tc, dr, dc, size, tile, sr, sc):
    if size == 1:
        return
    t = tile
    tile += 1
    #分棋盘
    s = size // 2
    #特殊在左上
    if dr < tr + s and dc < tc + s:
        #在就循环递归
        chessboard_cover(board, tr, tc, dr, dc, s, t, sr, sc)
    else:
        #不在就标骨牌占用并创一个特殊格子进行迭代
        board[tr + s - 1][tc + s - 1] = t
        chessboard_cover(board, tr, tc, tr + s - 1, tc + s - 1, s, t, tr+s-1, tc+s-1)
    #特殊在右上
    if dr < tr + s and dc >= tc + s:
        chessboard_cover(board, tr, tc + s, dr, dc, s, t, sr, sc)
    else:
        board[tr + s - 1][tc + s] = t
        chessboard_cover(board, tr, tc + s, tr + s - 1, tc + s, s, t, tr+s-1, tc+s)
    #左下
    if dr >= tr + s and dc < tc + s:
        chessboard_cover(board, tr + s, tc, dr, dc, s, t, sr, sc)
    else:
        board[tr + s][tc + s - 1] = t
        chessboard_cover(board, tr + s, tc, tr + s, tc + s - 1, s, t, tr+s, tc+s-1)
    #右下
    if dr >= tr + s and dc >= tc + s:
        chessboard_cover(board, tr + s, tc + s, dr, dc, s, t, sr, sc)
    else:
        board[tr + s][tc + s] = t
        chessboard_cover(board, tr + s, tc + s, tr + s, tc + s, s, t, tr+s, tc+s)
#计算k为2，4，6
start_time = time.time()
K = [2, 4, 6]
for k in K:
    sizes = [2**k]
    for size in sizes:
        #初始化棋盘
        board = [[0 for _ in range(size)] for _ in range(size)]
        #随机特殊格子
        special_cell = (random.randint(0, size - 1), random.randint(0, size - 1))
        #骨牌占用
        tile = 1
        chessboard_cover(board, 0, 0, special_cell[0], special_cell[1], size, tile, special_cell[0], special_cell[1])
        #计算占用大小
        total_size = sum(sys.getsizeof(row) for row in board) + sys.getsizeof(board)
        print(f"棋盘尺寸: {size}, 特殊方格: {special_cell}, 字节: {total_size} bytes")
        #打印棋盘
        for row in board:
            print(row)
        print("\n")
end_time = time.time()
execution_time = end_time - start_time
print(f"程序的执行时间：{execution_time}秒")
