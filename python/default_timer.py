from timeit import default_timer as timer
from time import sleep

count = 0

start = timer()
print "\nstart: ", start

while ( count < 200000 ):
    print "\nstart: ", start
    count+=1

end = timer()
print "end  : ", end
print "{:.10f}".format(end - start)
