+#include<stdio.h>
+#include<stdlib.h>
+#include<string.h>
+
+#define BUFFER_SIZE 10
+
+typedef struct {
+     char type;
+     int amount;
+     char unit;
+}item;
+
+item bufer[BUFFER_SIZE];
+int first = 0;
+int last = 0;
+
+void produce(item *i){
+       while ((first + 1) % BUFFER_SIZE == last){
+             //no free buffer item      
+       }
+       memcpy(&buffer[first], i, sizeof(item));
+       first=(first+1) % BUFFER_SIZE;
+}
+item *consume(){
+       item *i = (item *)malloc(sizeof(item));
+       while (first == last){
+             //nothing to consume
+       }
+       memcpy(i, &buffer[last], sizeof(item));
+       last = (last+1) % BUFFER_SIZE;
+       return i;
+}
+
+void *producepthread(void *param){
+     item item_x;
+     item_x.type = '1';
+     item_x.amount = 0;
+     item_x.unit = '1';
+
+     printf("\Producing item x: type=%c amount=%d unit=%c\n",item_x.type,item_x.amount,item_x.unit);
+     produce(&item_x);
+     printf("first = %d last =%d\n,first,last);
+
+     item item_y;
+     item_y.type = '0';
+     item_y.amount = 1;
+     item_y.unit = '0';
+
+     printf("\Producing item y: type=%c amount=%d unit=%c\n",item_y.type,item_y.amount,item_y.unit);
+     produce(&item_y);
+     printf("first = %d last =%d\n,first,last);
+
+     item item_z;
+     item_z.type = '1';
+     item_z.amount = 1;
+     item_z.unit = '0';
+
+     printf("\Producing item z: type=%c amount=%d unit=%c\n",item_z.type,item_z.amount,item_z.unit);
+     produce(&item_z);
+     printf("first = %d last =%d\n,first,last);
+}
+
+void *consumethread(void *param){
+
+     printf("After consumed once:\n");
+     consume();
+     printf("first = %d last =%d\n,first,last);
+     printf("After consumed twice:\n");
+     consume();
+     printf("first = %d last =%d\n,first,last);
+}
+
+int main(){
+     pthread_t p1, c1;  
+     pthread_create(&p1,NULL,producethread,NULL);
+     pthread_join(p1,NULL);
+     pthread_create(&c1,NULL,consumethread,NULL);
+     pthread_join(c1,NULL);
+     return 0;
+}
+
