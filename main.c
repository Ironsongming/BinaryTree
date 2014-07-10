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

	
	//提示信息
	print("please enter your binaryTree");
	newLine();
	
	//创建一棵二叉树，并完成初始化
	//初始化在创建函数内完成
	binaryTree=CreateBiTree();	

	rootValue=binaryTree->data;
	
	//创建完二叉树，检验是否为空
	if(BiTreeEmpty(binaryTree)){
		print("This tree isn't empty");
		newLine();
	}else{
		print("This tree is empty");
	}
	
	//查看该二叉树的层数
	print("The depth of this tree is : ");
	Log(BiTreeDepth(binaryTree));
	newLine();
	
	//该二叉树的各种遍历
	//先根遍历
	print("PreOrderTraverse is ");
	PreOrderTraverse(binaryTree,Log);
	newLine();
	
	//中根遍历
	print("InOrderTraverse is ");
	InOrderTraverse(binaryTree,Log);
	newLine();

	//后根遍历
	print("PostOrderTraverse is ");
	PostOrderTraverse(binaryTree,Log);
	newLine();

	//层序遍历
	print("LevelOrderTraverse is ");
	LevelOrderTraverse(binaryTree,Log);
	newLine();
	
	//显示某个节点的左孩子和右孩子，双亲节点，以根节点的左孩子为测试结点
	
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
	//显示某个节点的右兄弟，以根节点的左孩子为示例
	if(RightSibling(binaryTree,binaryTree->lChild)){
		print("data of RightSibling of lChild is ");
		Log(RightSibling(binaryTree,binaryTree->lChild)->data);
	}else{
		printf("No RightSibling of this Node");
	}

	newLine();
	//显示某个节点的左兄弟，以根节点的右孩子为示例
	if(LeftSibling(binaryTree,binaryTree->lChild)){
		print("data of LeftSibling of rChild is ");
		Log(LeftSibling(binaryTree,binaryTree->lChild)->data);
	}else{
		printf("No LeftSibling of this Node");
	}	

	newLine();
	//添加新结点，在最低层的最左结点添加左孩子
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
	//添加新结点，在最低层的最左结点添加右孩子
	print("enter the data of your new Node : ");
	e=CreateNode();
	InsertChild(binaryTree,temp_tree,1,e);
	print("After function InsertChild(rChild) PostOrderTraverse is ");
	PreOrderTraverse(binaryTree,Log);

	newLine();
	
	//删除结点，删除根结点的
	DeleteChild(binaryTree,Parent(binaryTree,e),0);
	print("After function DeleteChild(lChild) PostOrderTraverse is ");
	PreOrderTraverse(binaryTree,Log);
	
	newLine();
	
	DeleteChild(binaryTree,Parent(binaryTree,e),1);
	print("After function DeleteChild(rChild) PostOrderTraverse is ");
	PreOrderTraverse(binaryTree,Log);
	
	newLine();
	//更改某个节点的值，为了方便展示，将树内的数字全部加1
	scanAndchangeBiTree(binaryTree,Assign);
	//更改后该树的先根遍历
	print("After function Assign PostOrderTraverse is ");
	PreOrderTraverse(binaryTree,Log);

	
	newLine();
	//销毁该树
	DestroyBiTree(binaryTree);
	if(binaryTree->data!=rootValue){
		printf("this binaryTree has been destroyed");
	}
	


	
	
}

