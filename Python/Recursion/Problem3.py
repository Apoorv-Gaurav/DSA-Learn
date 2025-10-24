#https://www.youtube.com/watch?v=ngCos392W4w
'''
Hint:
count_partition(0,0)-->1
count_partition(0,1)-->1
count_partition(0,2)-->1   if n=0 -->count_partition(n,m)-->1
count_partition(1,0)-->0
count_partition(2,0)-->0   if m=0 -->count_partition(n,m)-->0

c_p(a,b) = c_p(a-b,b) + c_p(a,b-1)


'''
def count_partitions(n, m):
    if n == 0:
        return 1
    elif m == 0 or n < 0:
        return 0
    else:
        return count_partitions (n-m, m) + count_partitions(n, m-1)
n,m=7,4
print(count_partitions(n,m))