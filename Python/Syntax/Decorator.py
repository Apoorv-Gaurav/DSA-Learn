def my_decorator(func):
    def wrapper():
        print("Before the function runs")
        func()
        print("After the function runs")
    return wrapper

@my_decorator
def greet():
    print("Hello!")

greet()


import time

def timer(func):
    def wrapper():
        start = time.time()
        func()
        end = time.time()
        print(f"Time taken: {end - start:.4f} seconds")
    return wrapper

@timer
def slow_function():
    time.sleep(2)
    print("Function finished!")

slow_function()
