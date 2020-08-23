from resettabletimer import ResettableTimer

def func1():
    print "hello"

# Create resettable timer
t = ResettableTimer (5, func1)

# Starting and canceling work similarly than with threading.Timer
t.start()

# Wait 1-5 seconds

# Reset the timer
t.reset()
