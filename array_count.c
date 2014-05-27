#include <stdio.h>

void show(int row,int col);
void count_array(int test[][100],int row,int col);

void count_array(int test[][100],int row,int col){
	test[row][col] += 1;
}

void format(int test[][100],int row,int col){
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			test[i][j] = 0;
		}
	}
}

void last_show(int test[][100],int row,int col){
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			printf("%d",test[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void show(int row,int col){
	int i,j;
	int now_row=row-1,now_col=col-1;
	int test[100][100];
	format(test,row,col);
	while(test[0][0] != 9){
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				printf("%d",test[i][j]);
			}
			printf("\n");
		}
		
		if((now_col == 0)&&(test[now_row][now_col] == 9)){
			now_row -= 1;
			now_col = col-1;
		}else if(test[now_row][now_col] == 9){
			now_col--;
		}
		count_array(test,now_row,now_col);
		printf("\n");
	}
	last_show(test,row,col);
}
int main(){
	int col,row;
	printf("please Input >> Row Col\n");
	scanf("%d %d",&row,&col);
	show(row,col);
	return 0;
}

