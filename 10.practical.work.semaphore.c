+#include<stdio.h>
+#include<stdlib.h>
+#include<string.h>
+#include<pthread.h>
+#include<semaphore.h>
+
+#define BUFFER_SIZE 10
+
+typedef struct {
+     char type; // 0=fried chicken, 1=French fries
+     int amount; // pieces or weight
+     char unit;  // 0=piece, 1=gram
+}item;
+
+sem_t s;
+int sem_init(sem_t *sem, int pshared, int b);
+int sem_wait(sem_t *sem);
+int sem_post(sem_t *sem); 
+int sem_destroy(sem_t *sem);
+
+item bufer[BUFFER_SIZE];
+int first = 0;
+int last = 0;
+
+void produce(item *i){
+       while ((first + 1) % BUFFER_SIZE == last){
+             //no free buffer item      
+       }
+       sem_wait(&s);
+       memcpy(&buffer[first], i, sizeof(item));
+       first=(first+1) % BUFFER_SIZE;
+       sem_post(&s);
+}
+item *consume(){
+       item *i = (item *)malloc(sizeof(item));
+       while (first == last){
+             //nothing to consume
+       }
+       sem_wait(&s);
+       memcpy(i, &buffer[last], sizeof(item));
+       last = (last+1) % BUFFER_SIZE;
+       sem_post(&s);
+       return i;
+}
+
+void *produce(void *param){
+     item x, y, z;
+     x.type = '1';
+     x.amount =2;
+     x.unit = '1';
+
+     y.type = '0';
+     y.amount =5;
+     y.unit = '0';
+
+     z.type = '0';
+     z.amount =8;
+     z.unit = '1';
+
+     printf("Producing item x: type=%c amount=%d unit=%c\n",x.type,x.amount,x.unit);
+     produce(&x);
+     printf("Produced item x: first = %d last =%d\n",first,last);
+     printf("Producing item y: type=%c amount=%d unit=%c\n",y.type,y.amount,y.unit);
+     produce(&y);
+     printf("Produced item y: first = %d last =%d\n",first,last);
+     printf("Producing item z: type=%c amount=%d unit=%c\n",z.type,z.amount,z.unit);
+     produce(&z);
+     printf("Produced item z: first = %d last =%d\n",first,last);
+}
+
+void *consume(void *param){
+
+     printf("Consume first production:\n");
+     consume();
+     printf("Consumed :first = %d last =%d\n,first,last);
+     printf("Consume second production:\n");
+     consume();
+     printf("Consumed :first = %d last =%d\n,first,last);
+     printf("Consume third production:\n");
+     consume();
+     printf("Consumed :first = %d last =%d\n,first,last);
+}
+
+int main(){
+     pthread_t p1, c1;  
+     pthread_create(&p1, NULL, produce, NULL);
+     pthread_join(p1, NULL);
+     pthread_create(&c1, NULL, consume, NULL);
+     pthread_join(c1, NULL);
+     return 0;
+}
+
