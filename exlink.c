    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void)
    {
    	char c;
    	c = getchar();
    	while(c == 's'){
    		system("start http://www.example.com");
    		c = getchar();
    	}
    	return 0;
    }
