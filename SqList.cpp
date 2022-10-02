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
	printf("��������Ҫ������˳���Ԫ�ظ��� n=");
	scanf("%d",&n);
	printf("\n��������Ҫ������˳���\n");
	for(i=0; i<n; i++){
		scanf("%d",&L.elem[i]);
		L.length++;
	}
	printf("�����ɹ���");
}

//����ĳԪ�����ڵ�λ�� 
int Location(SeqList L, datatype x){
	int i;
	for(i=0; i<L.length; i++){
		if(L.elem[i] == x){
			return i+1;
		}
	} 
	
	return -1;//����û�и�Ԫ�� 
}

//����Ԫ��
void InsertElem(SeqList &L, datatype e){
	int i,n;
	printf("��������Ҫ�����λ�� n=");
	scanf("%d",&n);
	
	if((L.length+1)>MAX){
		printf("\n����Ԫ�����������ܲ���\n");
	}else if(n>L.length+1){
		printf("�����λ�ò��Ϸ���");
	}else{
		//������� 
		for(i=L.length-1; i>=n-1; i--){
			L.elem[i+1] = L.elem[i];
		}
		L.elem[n-1] = e;
		L.length++;
		printf("\n����ɹ�!\n");
	}
}

//ɾ������ĳ����
void elemDelete(SeqList &L, datatype e){
	int i,j;
	
	i = Location(L,e);
	while(i==-1){
		datatype n;
		printf("�������ҵ�Ԫ�ز��ڱ��У�������������Ҫɾ����Ԫ��");
		scanf("%d",&n);
		i = Location(L,n);
	}
	for(j=i; j<L.length; j++){
		L.elem[j-1] = L.elem[j];
	}
	printf("\nɾ���ɹ���\n");
	L.length--;
} 

//��ʾ��ǰ˳���
void ShowList(SeqList L){
	int i;
	printf("\n��ǰ˳���Ԫ��Ϊ��\n");
	for(i=0; i<L.length; i++){
		printf("%d ",L.elem[i]);
	}
	printf("\n");
} 

int main(void) {
	int operation = -1; //����ѡ���
	 
	SeqList L1;
	SeqList L2;
	SeqList LC;
	
	InitList(L1);
	InitList(L2);
	CreateList(L1);
	CreateList(L2);
	
	printf("\n**************************\n");
	printf("\n���������1 ɾ��ĳԪ�� 2 ����ĳԪ�� 3 ����ĳԪ�� 4 �����ǰ˳��� 5 �˳�\n");
	while(operation<=5){
		scanf("%d",&operation);
		switch(operation){
			int n;
			case 1:
				printf("��������Ҫɾ����Ԫ�أ�n=");
				scanf("%d",&n); 
				elemDelete(L,n);
				break;
			case 2:
				printf("��������Ҫ�����Ԫ�� n=");
				scanf("%d",&n);
				InsertElem(L,n);
				break;
			case 3:
				datatype x;
				printf("��������Ҫ���ҵ�Ԫ�� x=");
				scanf("%d",&x);
				printf("��Ԫ����˳����е�λ��Ϊ%d\n",Location(L,x));
				break;
			case 4:
				ShowList(L);
			case 5:
				break;
		}
	}
	
	return 0;
}
