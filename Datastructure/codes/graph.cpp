#include <iostream>
#include<stdlib.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct AdjList{
    struct Node *head;
};

struct Graph{
    int v;
    struct AdjList *array;
};

struct Node* createnode(int data){
    struct Node *newnode;
    newnode =(struct Node *)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

struct Graph* creategraph(int a){
    struct Graph *graph;
    graph=(struct Graph *)malloc( sizeof(Graph));
    graph->v=a;
    graph->array=(struct AdjList*)malloc( a*sizeof(struct AdjList));
    for(int i=0;i<a;i++){
        graph->array[i].head=NULL;   
    }
    return graph;
}

void addedge(struct Graph *graph,int src,int dest){
    struct Node *newnode;
    newnode=createnode(dest);
    newnode->next=graph->array[src].head;
    graph->array[src].head=newnode;
    //adding node at the beggining
    //as a graph is undirected add edges on both vertices
    //create a another newnode for storing because it is a undirected graph
    //array are auto deferenceble so i used (.) instead of (->) so you need not to dereference
    newnode=createnode(src);
    newnode->next=graph->array[dest].head;
    graph->array[dest].head=newnode;
}

void printgraph(struct Graph *graph){
    int v;
    struct Node *temp;
    for(v=0;v<graph->v;v++){
        temp=graph->array[v].head;
        cout<<"adajacensy list of vertex "<<v<<endl;
        while(temp){
            cout<<"->"<<temp->data;
            temp=temp->next;
        }
        cout<<"\n";
    }
}

int main() {
	// your code goes here
	struct Graph *graph;
	graph=creategraph(5);
	addedge(graph,0,1);
	addedge(graph, 0, 4);
	addedge(graph, 1, 2); 
	addedge(graph, 1, 3); 
	addedge(graph, 1, 4);
	addedge(graph, 2, 3);
	addedge(graph, 3, 4); 
	printgraph(graph);
	return 0;
	
	
}



