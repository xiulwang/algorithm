#coding:utf-8
def Merge(L,stratL,endL,endR):  #左边数组的起点，终点，右边数组的终点
    a = L[stratL:endR+1]    #要排序的子序列复制出来

    i = stratL  #左边数组的起点
    j = endL+1  #右边数组的起点
    for k in range(0,endR-stratL+1):
        if i > endL:    #左边数组已经被遍历完
            a[k:endR-stratL+1] = L[j:endR+1]
            break
        elif j > endR:  #右边数组已经被遍历完
            a[k:endR-stratL+1] = L[i:endL+1]
            break
        elif L[i] < L[j]:
            a[k] = L[i]
            i += 1
        elif L[i] >= L[j]:
            a[k] = L[j]
            j += 1

    L[stratL:endR+1] = a    #把排好序的子数组复制给原数组


def mergesort(L,start,end):
    if(start==end):
        return
    else:
        mergesort(L,start,start+(end-start)/2)
        mergesort(L,start+1+(end-start)/2,end)
        Merge(L,start,start+(end-start)/2,end)

#main function
f = open('test.txt','r')
L = []
data = f.readline()
L = data.split(' ')
for index, item in enumerate(L):
    L[index] = int(item)    #covert str into int
f.close()
mergesort(L,0,len(L)-1)

print L