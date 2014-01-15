# include <stdio.h>
# include <pthread.h>


int i = 0;


void* incrementor(){
    for(int x = 0; x < 1000000; x++){
        i++;
    }
    return NULL;
}

void* decrementor(){
    for(int x = 0; x < 1000000; x++){
        i--;
    }
    return NULL;
}

int main(){

    // Thread 1:
    pthread_t thread1;
    pthread_create(&thread1, NULL, incrementor, NULL);
   
    // Thread 2:
    pthread_t thread2;
    pthread_create(&thread2, NULL, decrementor, NULL);
    
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL); 

    
    printf("Done: %i\n", i);
    return 0;
    
};
