#include "myShell.h" 

int shell_num_builtins() {
return sizeof(builtins) / sizeof(struct builtin);
 }


void shell_exec(char **args) {
	int i;
	pid_t child_pid;
	for (i = 0; i < shell_num_builtins(); i++) {
		if (strcmp(args[0], builtins[i].name) == 0) {
			builtins[i].func(args);
			return;
		}
	}

	    child_pid = fork();
	    if (child_pid == 0) {
		    execvp(args[0], args);
		    perror("shell");
		     exit(1);
	    } else if (child_pid > 0) {
		    int status;
		    do {
			    waitpid(child_pid, &status, WUNTRACED);
		    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
	    } else {
		    perror("shell");
	    }
}


