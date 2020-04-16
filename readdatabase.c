//gcc -o ex readdatabase.c libbt/lib/libbt.a


#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
#include<stdlib.h>
#include"libbt/inc/btree.h"

char *tachtu(char *line, char *word);
//void ReadFile(FILE *fptr, char *filename);
void insertBtree(FILE *fptr, char *filename, BTA *root);
void findword(BTA *tree, char *word){
	char mean [100000];
	int size ;
   	if(btsel(tree, word, mean, 100000*sizeof(char), &size))
		printf("cannot find word\n");
	else
		printf("%s\n%s\n\n", word, mean);
}

int main(){
	FILE *fptr;
	char filedict[80] = "td.dict";
	char filedatabase[80] = "database.dat";
	BTA *tree;
	int size ;
	char word[80], mean[100000];
	btinit();
	tree = btopn(filedatabase, 0, 0);
	if(tree==NULL){
		 tree = btcrt(filedatabase, 0 , 0);
	}
	insertBtree(fptr, filedict, tree);
    printf("Nhap vao tu: ");
	__fpurge(stdin);
	gets(word);
	//findword(tree, str);
	btsel(tree, "", mean, sizeof(char)*100000, &size);
	while((btseln(tree, word, mean, sizeof(char)*100000, &size))==0)
		printf("%s\n%ld\n\n", word, strlen(word));	
//	if(btsel(tree, word, mean, sizeof(char)*100000, &size)==0) 			printf("%s\n%s\n\n", word, mean);
	//printf("%d\n", bfndky(tree, word, (int *)mean));	
	btcls(tree);
	return 0;
}

char *tachtu(char *line, char *word){
	for(int j=1; j<strlen(line); j++){
		if(line[j]=='/'){
			word[j-1]='\0';
			break;
		}
		else
			word[j-1]=line[j];
	}
   return word ;
}		

/*void ReadFile(FILE *fptr, char *filename){
	char word[200];
	char mean[1000], line[200];
	int count = 0;
	if((fptr = fopen(filename, "r"))==NULL){
		printf("Cannot open file\n");
		exit(1);
	}
	else{
		while((!feof(fptr))){
	   		fgets(line, 80, fptr);
			line[strlen(line)-1]='\0';
			if(line[0]=='@'){
				tachtu(line, word);
				printf("%s\n", word);
				mean[0] = '\0';
					count++ ;
			}
			else {
				strcat(mean,line);				
			}
		}
	}
	fclose(fptr);
}
*/
void insertBtree(FILE *fptr, char *filename, BTA *root){
	char word[80];
	char mean[100000], line[80], *c;
	mean[0] = '\0';
	int count = 0, flag1 = 1, flag = 0;
	if((fptr = fopen(filename, "r"))==NULL){
		printf("Cannot open file\n");
		exit(1);
	}
	else{
		while((c != NULL) || flag == 0){
			c = fgets(line, 80, fptr);
			line[strlen(line)-1]='\0';
			if(line[0]=='@'|| c==NULL){
				if(flag1==0){
					btins(root, word, mean, strlen(mean));
//			   		printf("%s\n%ld\n\n", word, strlen(word));
					count ++ ;
					mean[0] = '\0';
				 }
				tachtu(line, word);
				
				flag1 = 0;
				if(c == NULL) flag = 1;
			}
			else {
				strcat(mean,line);
			}
		}				   		
	}
//	printf("%d\n", count);
	fclose(fptr);	
}
