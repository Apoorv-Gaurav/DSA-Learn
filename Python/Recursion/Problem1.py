def func(n):
    if n == 0:
        return 0
    else:
        return n + func(n-1)

n=10
print(func(10))