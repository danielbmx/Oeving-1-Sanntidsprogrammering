package main

import (
    . "fmt"
    . "runtime"
    . "time"
)

var i = 0

func incrementor(){
    for x := 0; x < 1000000; x++ {
        i++
    }
}

func decrementor(){
    for x := 0; x < 1000000; x++ {
        i++
    }
}

func main() {
    GOMAXPROCS(NumCPU())        
    go incrementor()                  
    go decrementor()
    
    Sleep(100*Millisecond)
    Println("Done:", i);
    
    Println(NumCPU())
}
