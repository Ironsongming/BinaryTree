typedef int Item;
typedef int boolean;

typedef struct node{
	struct node *lChild;
	struct node *rChild;
	Item data;
}Node,BinaryTree;


BinaryTree * InitBiTree();

void DestroyBiTree(BinaryTree * binaryTree);

BinaryTree * CreateBiTree();

void ClearBiTree(BinaryTree * binaryTree);

boolean BiTreeEmpty(BinaryTree * binaryTree);

int BiTreeDepth(BinaryTree * binaryTree);

Node * Root(BinaryTree * binaryTree);

Item Value(BinaryTree * binaryTree,Node * e);

void Assign(BinaryTree * binaryTree,Node * e,Item new_data);

Node * Parent(BinaryTree * binaryTree,Node * e); 

Node * LeftChild(BinaryTree * binaryTree,Node * e);

Node * RightChild(BinaryTree * binaryTree,Node * e);

Node * LeftSibling(BinaryTree * binaryTree,Node * e);

Node * RightSibling(BinaryTree * binaryTree,Node * e);

boolean InsertChild(BinaryTree * binaryTree,Node *p,int LR,Node * node);

boolean DeleteChild(BinaryTree * binaryTree,Node *p,int LR);

void PreOrderTraverse(BinaryTree * binaryTree,void(*visit)());

void InOrderTraverse(BinaryTree * binaryTree,void(*visit)());

void PostOrderTraverse(BinaryTree * binaryTree,void(*visit)());

void LevelOrderTraverse(BinaryTree * binaryTree,void(*visit)());

//�����Ǹ�������
//�����������͵���Assign�����޸Ľ���Itemֵ
void scanAndchangeBiTree(BinaryTree * binaryTree,void(*change)());
//����
void newLine();
//�����µĽ��
Node * CreateNode();

