print("before functionA")
def functionA():
    print("Function A")

print("before functionB")
def functionB():
	print("Function B")   
#    print("Function B {}".format(math.sqrt(100)))

if __name__ == '__main__':
    functionA()
    functionB()

print("before import")
import math

print("before __name__ guard")

print("after __name__ guard")
