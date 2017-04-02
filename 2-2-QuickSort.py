import random

def swap(L,a,b):
    temp = L[a]
    L[a] = L[b]
    L[b] = temp


def partition(L,l,r):
    randomindex = random.randint(l,r)
    swap(L,l,randomindex)
    p = L[l]
    i = l+1
    for j in range(l+1,r+1):
        if L[j] < p:
            swap(L,j,i)
            i += 1
    swap(L,l,i-1)
    return i-1


def quicksort(L,start,end):
    if start == end:
        return
    else:
        ind = partition(L,start,end)
        if ind == start:
            quicksort(L,start+1,end)
        elif ind == end:
            quicksort(L,start,end-1)
        else:
            quicksort(L,start,ind-1)
            quicksort(L,ind+1,end)


f = open('test.txt','r')
L = []
data = f.readlines()
for line in data:
    temp = line.strip('\n')
    L.append(temp)
f.close()
for index, item in enumerate(L):
    L[index] = int(item)    #covert str into int

quicksort(L,0,len(L)-1)

print L