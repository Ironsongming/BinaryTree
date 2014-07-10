#include<stdio.h>
#include"NodeQueue.h"

void Log(Item data){
	printf("%d",data);
}

void print(char *s){
	printf("%s",s);
}


void main(){
	
    BinaryTree * binaryTree=NULL;
	Node * e=NULL;
	BinaryTree * temp_tree=NULL;
	Item rootValue;

	
	//��ʾ��Ϣ
	print("please enter your binaryTree");
	newLine();
	
	//����һ�ö�����������ɳ�ʼ��
	//��ʼ���ڴ������������
	binaryTree=CreateBiTree();	

	rootValue=binaryTree->data;
	
	//������������������Ƿ�Ϊ��
	if(BiTreeEmpty(binaryTree)){
		print("This tree isn't empty");
		newLine();
	}else{
		print("This tree is empty");
	}
	
	//�鿴�ö������Ĳ���
	print("The depth of this tree is : ");
	Log(BiTreeDepth(binaryTree));
	newLine();
	
	//�ö������ĸ��ֱ���
	//�ȸ�����
	print("PreOrderTraverse is ");
	PreOrderTraverse(binaryTree,Log);
	newLine();
	
	//�и�����
	print("InOrderTraverse is ");
	InOrderTraverse(binaryTree,Log);
	newLine();

	//�������
	print("PostOrderTraverse is ");
	PostOrderTraverse(binaryTree,Log);
	newLine();

	//�������
	print("LevelOrderTraverse is ");
	LevelOrderTraverse(binaryTree,Log);
	newLine();
	
	//��ʾĳ���ڵ�����Ӻ��Һ��ӣ�˫�׽ڵ㣬�Ը��ڵ������Ϊ���Խ��
	
	print("The rChild and lChild of the lChild of root are ");
	newLine();
	if(LeftChild(binaryTree,binaryTree->lChild)){
		print("data of lChild is ");
		Log(LeftChild(binaryTree,binaryTree->lChild)->data);
	}else{
		printf("No lChild of this Node");
	}
	newLine();
	
	if(RightChild(binaryTree,binaryTree->lChild)){
		print("data of rChild is ");
		Log(RightChild(binaryTree,binaryTree->lChild)->data);
	}else{
		printf("No rChild of this Node");
	}
	newLine();

	print("The parent of the lChild of root are ");
	newLine();
	if(Parent(binaryTree,binaryTree->lChild)){
		print("data of parent is ");
		Log(Parent(binaryTree,binaryTree->lChild)->data);
	}else{
		printf("No lChild of this Node");
	}

	newLine();
	//��ʾĳ���ڵ�����ֵܣ��Ը��ڵ������Ϊʾ��
	if(RightSibling(binaryTree,binaryTree->lChild)){
		print("data of RightSibling of lChild is ");
		Log(RightSibling(binaryTree,binaryTree->lChild)->data);
	}else{
		printf("No RightSibling of this Node");
	}

	newLine();
	//��ʾĳ���ڵ�����ֵܣ��Ը��ڵ���Һ���Ϊʾ��
	if(LeftSibling(binaryTree,binaryTree->lChild)){
		print("data of LeftSibling of rChild is ");
		Log(LeftSibling(binaryTree,binaryTree->lChild)->data);
	}else{
		printf("No LeftSibling of this Node");
	}	

	newLine();
	//����½�㣬����Ͳ���������������
	print("enter the data of your new Node : ");
	e=CreateNode();
	temp_tree=binaryTree;
	while(temp_tree->lChild){
		temp_tree=temp_tree->lChild;
	}
	InsertChild(binaryTree,temp_tree,0,e);
	print("After function InsertChild(lChild) PostOrderTraverse is ");
	PreOrderTraverse(binaryTree,Log);
	
	newLine();
	//����½�㣬����Ͳ������������Һ���
	print("enter the data of your new Node : ");
	e=CreateNode();
	InsertChild(binaryTree,temp_tree,1,e);
	print("After function InsertChild(rChild) PostOrderTraverse is ");
	PreOrderTraverse(binaryTree,Log);

	newLine();
	
	//ɾ����㣬ɾ��������
	DeleteChild(binaryTree,Parent(binaryTree,e),0);
	print("After function DeleteChild(lChild) PostOrderTraverse is ");
	PreOrderTraverse(binaryTree,Log);
	
	newLine();
	
	DeleteChild(binaryTree,Parent(binaryTree,e),1);
	print("After function DeleteChild(rChild) PostOrderTraverse is ");
	PreOrderTraverse(binaryTree,Log);
	
	newLine();
	//����ĳ���ڵ��ֵ��Ϊ�˷���չʾ�������ڵ�����ȫ����1
	scanAndchangeBiTree(binaryTree,Assign);
	//���ĺ�������ȸ�����
	print("After function Assign PostOrderTraverse is ");
	PreOrderTraverse(binaryTree,Log);

	
	newLine();
	//���ٸ���
	DestroyBiTree(binaryTree);
	if(binaryTree->data!=rootValue){
		printf("this binaryTree has been destroyed");
	}
	


	
	
}

