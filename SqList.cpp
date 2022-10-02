#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef int datatype; 

typedef struct{
	datatype elem[MAX];
	int length;
}SeqList;

SeqList InitList(SeqList &L){
	L.length = 0;
}

void CreateList(SeqList &L){
	int i,n;
	printf("请输入你要创建的顺序表元素个数 n=");
	scanf("%d",&n);
	printf("\n请输入你要创建的顺序表：\n");
	for(i=0; i<n; i++){
		scanf("%d",&L.elem[i]);
		L.length++;
	}
	printf("创建成功！");
}

//查找某元素所在的位置 
int Location(SeqList L, datatype x){
	int i;
	for(i=0; i<L.length; i++){
		if(L.elem[i] == x){
			return i+1;
		}
	} 
	
	return -1;//表内没有该元素 
}

//插入元素
void InsertElem(SeqList &L, datatype e){
	int i,n;
	printf("请输入你要插入的位序 n=");
	scanf("%d",&n);
	
	if((L.length+1)>MAX){
		printf("\n表中元素已满，不能插入\n");
	}else if(n>L.length+1){
		printf("插入的位置不合法！");
	}else{
		//插入操作 
		for(i=L.length-1; i>=n-1; i--){
			L.elem[i+1] = L.elem[i];
		}
		L.elem[n-1] = e;
		L.length++;
		printf("\n插入成功!\n");
	}
}

//删除表中某语言
void elemDelete(SeqList &L, datatype e){
	int i,j;
	
	i = Location(L,e);
	while(i==-1){
		datatype n;
		printf("你所查找的元素不在表中，请重新输入你要删除的元素");
		scanf("%d",&n);
		i = Location(L,n);
	}
	for(j=i; j<L.length; j++){
		L.elem[j-1] = L.elem[j];
	}
	printf("\n删除成功！\n");
	L.length--;
} 

//显示当前顺序表
void ShowList(SeqList L){
	int i;
	printf("\n当前顺序表元素为：\n");
	for(i=0; i<L.length; i++){
		printf("%d ",L.elem[i]);
	}
	printf("\n");
} 

int main(void) {
	int operation = -1; //操作选择符
	 
	SeqList L1;
	SeqList L2;
	SeqList LC;
	
	InitList(L1);
	InitList(L2);
	CreateList(L1);
	CreateList(L2);
	
	printf("\n**************************\n");
	printf("\n输入操作：1 删除某元素 2 插入某元素 3 查找某元素 4 输出当前顺序表 5 退出\n");
	while(operation<=5){
		scanf("%d",&operation);
		switch(operation){
			int n;
			case 1:
				printf("请输入你要删除的元素：n=");
				scanf("%d",&n); 
				elemDelete(L,n);
				break;
			case 2:
				printf("请输入你要插入的元素 n=");
				scanf("%d",&n);
				InsertElem(L,n);
				break;
			case 3:
				datatype x;
				printf("请输入你要查找的元素 x=");
				scanf("%d",&x);
				printf("此元素在顺序表中的位置为%d\n",Location(L,x));
				break;
			case 4:
				ShowList(L);
			case 5:
				break;
		}
	}
	
	return 0;
}
