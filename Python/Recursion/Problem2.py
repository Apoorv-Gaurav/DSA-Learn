#Hint: grid_path(m,n)=grid_path(m-1,n)+grid_path(m,n-1)
def grid_path(m,n):
    if m==1 or n==1:
        return 1
    else:
        return grid_path(m-1,n)+grid_path(m,n-1)
    
m,n=3,3
print(grid_path(m,n))