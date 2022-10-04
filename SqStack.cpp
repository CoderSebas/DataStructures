/*
 * 顺序栈 
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 100

typedef int elemtype;

typedef struct{
	elemtype *base;//栈底指针
	elemtype *top;//栈顶指针
	int stackSize;//栈可用的最大容量 
}SqStack;

//初始化 
bool InitStack(SqStack &S){
	S.base = (elemtype*)malloc(sizeof(elemtype)*MAXSIZE);//动态为栈分配内存 
	if(!S.base){//分配内存失败 
		return false;
	}
	S.top = S.base;//空栈的栈顶和栈底指向同一片空间
	S.stackSize = MAXSIZE;
	return true;
}

//销毁栈 
bool DestroyStack(SqStack &S){
	if(!S.base){//栈不存在 
		return false;
	}
	free(S.base);
	return true;
}

//元素入栈（增加元素） 
bool push(SqStack &S, elemtype e){
	if(S.top-S.base == S.stackSize){
		return false;//栈已满 
	}
	*S.top++ = e;//将元素放入栈顶，栈顶指针+1 
	return true;
}

//元素出栈（删除元素）
bool pop(SqStack &S, elemtype &e){
	if(S.top == S.base){
		return false;//空栈 
	}
	e = *--S.top;//栈顶指针-1，并将删除的元素用e带回 
	return true;
}

//获取栈顶元素
elemtype getTop(SqStack S){
	if(S.top != S.base){//栈不为空 
		return *(S.top-1);//栈顶指针指向的是下一个要入栈元素的位置，所以-1才是当前栈顶元素的值 
	}
} 

//清空栈内元素
bool clearStack(SqStack &S){
	S.top = S.base;
	return true;
} 

//判断是否空栈
bool isEmpty(SqStack S){
	if(S.top == S.base){
		return true;//空栈 
	}
	return false;//非空栈 
} 

//返回栈的长度
int Length(SqStack S){
	return  S.top-S.base;
} 

//遍历栈内元素
void StackTraverse(SqStack S){
	elemtype *p = S.top;
	while(p!=S.base){
		printf("%d ",*(p-1));
		p--;
	}
} 

int main(void){
	SqStack S;
	InitStack(S);
	push(S,1);
	push(S,2);
	push(S,3);
	push(S,4);
	push(S,5);
	
	StackTraverse(S);
	
	printf("\nLength:%d\n",Length(S));
	if(isEmpty(S)){
		printf("\n空栈\n");
	}else{
		printf("\n非空栈\n",Length(S));
	}
	
	printf("\nTop:%d\n",getTop(S));
	
	clearStack(S);
	StackTraverse(S);
	
	
	return 0;
}

