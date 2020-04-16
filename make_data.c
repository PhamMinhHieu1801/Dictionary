#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"libbt/inc/btree.h"
#include<stdio_ext.h>
void word_handle(char *word)
{
	char *word_temp;
	int len;
	word_temp = strtok(word,"/");
	len = strlen(word_temp);
	word_temp[len-1] = '\0';
	len--;
	for(int i=0;i<len;i++)
		word_temp[i] = word_temp[i+1];
	strcpy(word,word_temp);
}

void create_dic(BTA *root)
{
	char line[200];
	char word[20];
	char translation[100000];
	translation[0] = '\0';
	FILE *fp;
	if((fp = fopen("anhviet.txt", "r")) == NULL)
    {
        printf("Can not open anhviet.txt!\n");
        return;
    }
	int i;
    int first_word_flag = 1;
	int flag = 0;
    int word_count = 0;
	char *c;
	c = fgets(line,200,fp);
    do
    {
        if(line[0] == '@' || c == NULL)
        {
            if(first_word_flag == 0)
            {
                btins(root, word, translation, strlen(translation));
                translation[0] = '\0';
            }
            word_handle(line);
            strcpy(word, line);
            first_word_flag = 0;
            word_count ++;
			if(c == NULL)	flag = 1;
        }
        else
            strcat(translation, line);
		c = fgets(line, 200, fp);
    }while(c != NULL || flag == 0);
    printf("Inserted %d words into btree dictionary!\n", word_count);
    fclose(fp);	
}


int main()
{char word[80], mean[100000];
	int size;
    BTA *tree;
    btinit();
    tree = btcrt("database", 0, 0);
    create_dic(tree);
	printf("Nhap vao tu: ");
	__fpurge(stdin);
	gets(word);
	//btsel(tree, "", mean, sizeof(char)*100000, &size);
	//while((btseln(tree, word, mean, sizeof(char)*100000, &size))==0)
	//	printf("%s\n%ld\n\n", word, strlen(word));	
	if(btsel(tree, word, mean, sizeof(char)*100000, &size)==0) 			printf("%s\n%s\n\n", word, mean);
	//printf("%d\n", bfndky(tree, word, (int *)mean));	
    btcls(tree);
    return 0;
}
