// Data_Structure
// LinkList
// language: C++
// CSer: ljq_truth
 


# include<iostream>
# include<cstdlib>
// #include<bits/stdc++.h>

using namespace std;

#define MAXSIZE 1000

typedef int Elemtype;	// �������뽡׳�� 

/****** ����ṹ�� ******/ 
typedef struct LNode{		// ��������
	Elemtype data;
	struct LNode *next;
}LNode, *LinkList;

typedef struct DuLNode {  // ˫������
	Elemtype data;
	struct DuLNode* Prior;
	struct DuLNode* next;
}DuLNode, *DuLinkList;

/************************* ���� ***************************/ 

void Init( LinkList &L );  // ��ʼ�� 
void GetElem( LinkList L, int i, Elemtype &e );  // ȡֵ 
void CreateList_H(LinkList &L, int n);  // �������� ��ǰ�壩
void CreateList_R(LinkList &L, int n);  // �������� ����壩
LNode *LocateElem(LinkList L, Elemtype e);  // ���ң����ص�ַ
int LocateElem_int(LinkList L, Elemtype e);  // ���ң�����λ�� 
void print(LinkList &L);	// ��ӡ���� 
void ListInsert(LinkList &L, int i, Elemtype e);  // ���� 
void ListDelete(LinkList& L, int i);

/**********************************************************/ 

int main(){	 
	LinkList L,  H ;

	Init(L);

	//CreateList_H(H, 5);   // ǰ�巨 
	CreateList_R(L,5); 	   // ��巨 
	
	print(L);
	//print(LH);
	
	Elemtype e = 4;
	cout << "����L��ĵ�3��Ԫ��:" << LocateElem(L, e) << " |λ���ǣ�" << LocateElem_int(L, e);// ���� 
	
	int i = 2;
	ListInsert(L, i, e); 
	cout << ("\nInserted��");
	print( L);

	ListDelete(L, 3);
	cout << ("\nDeleted��");
	print(L);

	return 0;
}

/****** ��ʼ�� ******/ 
void Init( LinkList &L ){  // �����ʼ�� 
	L = new LNode;
	L -> next = NULL;
}

/****** ȡֵ ******/ 
void GetElem( LinkList L, int i, Elemtype &e ){  // ȡֵ 
	LNode *p = L->next;
	int j = 1;
	while(p && j < i){
		p = p -> next;
		++j;
	}
	if(!p || j > i) exit(-1);	
	e = p -> data;
} 

/****** ��������: ǰ�巨 ******/ 
void CreateList_H(LinkList &L, int n){	
	L = new LNode;
	L -> next = NULL;
	LNode *p;
	for(int i = 0; i < n; ++i){
		p = new LNode;
		cin >> p -> data;
		p -> next = L -> next;
		L -> next = p;
	}
}

/****** ��������: ��巨 ******/ 
void CreateList_R(LinkList &L, int n) {  
	L = new LNode;
	L -> next = NULL;
	LNode *r = L;
	LNode *p;
	for(int i = 0; i < n; ++i){
		p = new LNode;
		cin >> p -> data;
		p -> next = NULL;
		r -> next = p;
		r = p;
	}
}

/****** ������ӡ���� ******/ 
void print(LinkList &L){  
	LNode *p = L->next;
	while( p ){
		cout << p -> data << " ";
		p = p -> next;
	}
	cout << "\n" << endl;
}

/****** ���ң����ص�ַ ******/ 
LNode *LocateElem(LinkList L, Elemtype e){  
	LNode *p = L -> next;
	while(p && p -> data != e)
		p = p -> next;
	return p;
} 

/****** ���ң�����λ�� ******/ 
int LocateElem_int(LinkList L, Elemtype e){
	int num = 0;   // ��0��ʼ 
	LNode *p = L -> next;
	while(p && p -> data != e){ 
		p = p -> next;
		num++;
		} 
	return num;
} 

/****** ���� ******/
void ListInsert(LinkList &L, int i, Elemtype e){
	LNode *p = L;
	int j = 0;
	while(p && j < (i -1) ){
		p = p -> next; 
		++j;
	}
	if(!p || j > i-1) exit(-1);
	LNode * s = new LNode;
	s -> data = e;
	s -> next = p -> next;
	p -> next = s;
}
/*
void ListInsert_DuL(DuLinkList& L, int i, Elemtype e) {
	DuNode *p;

	if ( ! ( p = GetElem_Dul (L, i) )
		exit(-1);

	DuLNode *s = new DuLNode;

	s -> data = e;
	s -> prior = p -> prior;
	p -> prior -> next = s;
	s -> next = p;
	p -> prior = s;
}
*/

/****** ɾ�� ******/
void ListDelete(LinkList& L, int i){
	LNode* p;
	int j = 0;
	p = L;
	while ((p->next) && (j < i - 1)) {
		p = p->next;
		++j;
	}
	if (!(p->next) || (j > i - 1))  exit( - 1);
	 LNode *q = p->next;
	 p->next = q->next;
	 delete q;
}
/*
void ListDelete_DuL{
	if( ! ( p = GetElem_DuL(L, i ) ) )
		exit(-1)

	DuList *p;

	p -> prior -> next = p -> next;
	p -> next -> prior = p -> prior;

	delete p;
}
*/
/*****************************************************/
/*<����>[ ѭ������ ]
* �б�����Ϊ p! = L �� p -> next != L
* �ϲ�ѭ������  p = B -> next ->next; 
*                         B -> next = A -> next;
*                         A -> next = p;
/*****************************************************/
