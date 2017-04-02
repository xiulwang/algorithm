#coding:utf-8
import sys
sys.setrecursionlimit(800000)

def DFS1(G,i):
    global label
    global t
    global f
    label[i-1] = 1
    for m in range(1,len(G[i-1])):
        if label[G[i-1][m]-1] == 0:
            DFS1(G,G[i-1][m])
    t += 1
    f[t-1].append(i)


def DFS2(G,u):
    global label
    global leader
    global s
    label[u-1] = 1
    leader[s-1].append(u)
    for p in range(1,len(G[u-1])):
        if label[G[u-1][p]-1] == 0:
            DFS2(G,G[u-1][p])


f = open('test.txt','r')
G = []
data = f.readlines()
ind = 1
for line in data:
    line = line.split()
    line = map(int,line)
    if line[0] == ind:
        G.append(line)
        ind += 1
    elif line[0] < ind:
        G[ind-2].append(line[1])
    else:
        while ind < line[0]:
            G.append([ind])
            ind += 1
        G.append(line)
        ind += 1
f.close()

n = ind - 1
GRev = []   #反转矩阵
f = []      #存放节点与t值得对于关系
leader = [] #存放一个连通图内节点的母节点

for i in range(n):
    GRev.append([i+1])
    f.append([i+1])
    leader.append([i+1])
for i in range(n):
    for j in range(1,len(G[i])):
        GRev[G[i][j]-1].append(i+1)

t = 0   #第二次迭代顺序
s = 0   #母节点
label = [0]*n  #每个节点是否遍历标志

for i in range(n,0,-1):
    if label[i-1] == 0:
        DFS1(GRev,i)

label = [0]*n
for i in range(n,0,-1):
    u = f[i-1][1]
    if label[u-1] == 0:
        s = u
        DFS2(G,u)

# record = []
# for i in range(n):
#     record.append(len(leader[i])-1)
print leader



