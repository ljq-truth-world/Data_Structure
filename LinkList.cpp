// Data_Structure
// LinkList
// language: C++
// CSer: ljq_truth

# include<iostream>
# include<cstdlib>
// #include<bits/stdc++.h>

using namespace std;

#define MAXSIZE 1000

typedef int Elemtype;	// 提升代码健壮性 

/****** 定义结构体 ******/ 
typedef struct LNode{		// 单向链表
	Elemtype data;
	struct LNode *next;
}LNode, *LinkList;

typedef struct DuLNode {  // 双向链表
	Elemtype data;
	struct DuLNode* Prior;
	struct DuLNode* next;
}DuLNode, *DuLinkList;

/************************* 函数 ***************************/ 

void Init( LinkList &L );  // 初始化 
void GetElem( LinkList L, int i, Elemtype &e );  // 取值 
void CreateList_H(LinkList &L, int n);  // 创建链表 （前插）
void CreateList_R(LinkList &L, int n);  // 创建链表 （后插）
LNode *LocateElem(LinkList L, Elemtype e);  // 查找，返回地址
int LocateElem_int(LinkList L, Elemtype e);  // 查找，返回位置 
void print(LinkList &L);	// 打印链表 
void ListInsert(LinkList &L, int i, Elemtype e);  // 插入 
void ListDelete(LinkList& L, int i);

/**********************************************************/ 

int main(){	 
	LinkList L,  H ;

	Init(L);

	//CreateList_H(H, 5);   // 前插法 
	CreateList_R(L,5); 	   // 后插法 
	
	print(L);
	//print(LH);
	
	Elemtype e = 4;
	cout << "查找L里的第3个元素:" << LocateElem(L, e) << " |位置是：" << LocateElem_int(L, e);// 查找 
	
	int i = 2;
	ListInsert(L, i, e); 
	cout << ("\nInserted：");
	print( L);

	ListDelete(L, 3);
	cout << ("\nDeleted：");
	print(L);

	return 0;
}

/****** 初始化 ******/ 
void Init( LinkList &L ){  // 链表初始化 
	L = new LNode;
	L -> next = NULL;
}

/****** 取值 ******/ 
void GetElem( LinkList L, int i, Elemtype &e ){  // 取值 
	LNode *p = L->next;
	int j = 1;
	while(p && j < i){
		p = p -> next;
		++j;
	}
	if(!p || j > i) exit(-1);	
	e = p -> data;
} 

/****** 创建链表: 前插法 ******/ 
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

/****** 创建链表: 后插法 ******/ 
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

/****** 遍历打印链表 ******/ 
void print(LinkList &L){  
	LNode *p = L->next;
	while( p ){
		cout << p -> data << " ";
		p = p -> next;
	}
	cout << "\n" << endl;
}

/****** 查找，返回地址 ******/ 
LNode *LocateElem(LinkList L, Elemtype e){  
	LNode *p = L -> next;
	while(p && p -> data != e)
		p = p -> next;
	return p;
} 

/****** 查找，返回位置 ******/ 
int LocateElem_int(LinkList L, Elemtype e){
	int num = 0;   // 从0开始 
	LNode *p = L -> next;
	while(p && p -> data != e){ 
		p = p -> next;
		num++;
		} 
	return num;
} 

/****** 插入 ******/
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

/****** 删除 ******/
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
/*<补充>[ 循环链表 ]
* 判别条件为 p! = L 或 p -> next != L
* 合并循环链表  p = B -> next ->next; 
*                         B -> next = A -> next;
*                         A -> next = p;
/*****************************************************/
