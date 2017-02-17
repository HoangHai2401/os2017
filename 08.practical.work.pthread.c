+#include<stdio.h>
+#include<stdlib.h>
+#include<string.h>
+
+#define BUFFER_SIZE 10
+
+typedef struct {
+     char type; // 0=fried chicken, 1=French fries
+     int amount; // pieces or weight
+     char unit;  // 0=piece, 1=gram
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
