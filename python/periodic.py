import time, threading
from time import sleep

WAIT_SECONDS = 1

def foo():
    print(time.ctime())
    #threading.Timer(WAIT_SECONDS, foo).start()

object1 = threading.Timer(WAIT_SECONDS, foo)

while True:
    print object1.is_alive() 
    if ( object1.is_alive() == False ):
        object1.start()
        print "thread started"

    sleep(5)
    object1.cancel()
