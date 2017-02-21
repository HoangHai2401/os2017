+include<stdio.h>
+include<unistd.h>
+
+int main(){
+     print("Main before fork()\n");
+
+     int pidps = fork();
+     if (pidps == 0){
+           printf("\nIm child after fork(), lauching ps -ef\n");
+           char *args[]={"/bin/ps","-ef",NULL};
+           execvp("/bin/ps",args);
+           printf("Finished launching ps -ef\n");
+     }
+     else printf("\nIm parent after fork(), child is %d\n",pidps);
+
+     int pidfree = fork();
+     
+     if (pidfree == 0){
+           printf("Im child after fork(), launching free -h\n"); 
+           char *args[]={"free","-h",NULL};
+           execvp("free",args);
+           printf("Finished launching free -h\n");
+     }
+     else printf("\nIm parent after fork(), child is %d\n", pidfree);
+
+     return 0;
+}
