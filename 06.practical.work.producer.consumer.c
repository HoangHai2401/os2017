+#include<stdio.h>
+#include<stdlib.h>
+#include<string.h>
+
+#define BUFFER_SIZE 10
+
+typedef struct {
+     char type;
+     int amount;
+     chả unit;
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
+void log_val() {
+       printf("first = %d last =%d\n,first,last);
+}
+
+int main() {
+     item item_x;
+     item_x.type = '1';
+     item_x.amount = 0;
+     item_x.unit = '1';
+
+     printf("\Producing item x: type=%c amount=%d unit=%c\n",item_x.type,item_x.amount,item_x.unit);
+     produce(&item_x);
+     log_val();
+
+     item item_y;
+     item_y.type = '0';
+     item_y.amount = 1;
+     item_y.unit = '0';
+
+     printf("\Producing item y: type=%c amount=%d unit=%c\n",item_y.type,item_y.amount,item_y.unit);
+     produce(&item_y);
+     log_val();
+     
+     printf("\nAfter consumed once:\n");
+     consume();
+     log_val();
+}
+
