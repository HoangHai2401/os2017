+include<stdio.h>
+include<unistd.h>
+int main(){
+     print("Main before fork()\n")
+     int pid=fork();
+     if (pid == 0){
+           printf("Im child after fork(), lauching ps -ef\n");
+           char *args[]={"/bin/ps","-ef",NULL};
+           execvp("/bin/ps",args);
+           printf("Finished launching ps -ef\n");
+     }
+     else printf("Im parent after fork(), child is %d\n",pid);
+     pid = fork();
+     
+     if (pid ==0){
+           printf("Im child after fork(), launching free -h\n"); 
+           char *args[]={"free","-h",NULL};
+           execvp("free",args);
+           printf("Finished launching free -h\n");
+     }
+     else printf("Im parent afte fork(), child is %d\n, pid);
+     return 0;
+}
