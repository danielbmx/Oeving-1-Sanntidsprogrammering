from threading import Thread

i = 0

def incrementor():
    global i
    for x in range(0, 1000000):     
        i += 1
        
def decrementor():
    global i
    for x in range(0, 1000000):     
        i -= 1
        
def main():
    
    # Thread 1:
    adder_thr = Thread(target = incrementor)
    adder_thr.start()
    
    
    # Thread 2: 
    minus_thr = Thread(target = decrementor)
    minus_thr.start()
    
    adder_thr.join()
    minus_thr.join()
    
    
    
    print("Done: " + str(i))
    
    
    
    
main()
