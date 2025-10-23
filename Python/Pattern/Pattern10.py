n=5
k=0
for i in range(1,2*n):
    if i<=n:
      k+=1
    else:
       k-=1
    for j in range(0,k):
       print("*",end="")
    print()