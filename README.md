# Compiladores
```
for i <- 0 to n-1
    min <- i
    for j <- i+1 to n 
        if ( A[j] <-  A[min] )
            min <- j
    temp <- A[i]
    A[i] <- A[min]
    A[min] <- temp
``` 
