#include <map>
#include <list>
#include <QPair>

#include "tasks_rk2.h"
using namespace std;
//task1
Node::Node() {}
Node::Node(int nameNode) {}
Node::~Node() {}

Graph::Graph() {}
Graph::Graph(int countNodes) {}
Graph::~Graph() {}
int Graph::buildTreeBFS(int countNodes) {}
int Graph::buildTreeDFS(int countNodes) {}
void Graph::BFS() {}
void Graph::DFS() {}
std::pair<bool, list<int>> Graph::searchDFS(int nameNode)	 {}
std::pair<bool, list<int>> Graph::searchBFS(int nameNode)	{}

//task2

pair<int/*index el*/,int /*count call*/> binSearch(int* ar, int sizeAr, int el) {
    int static count1=0;
    int static right1=0;
    int middle =sizeAr/2;
    count1++;
    if (ar[middle]==el){
        return{middle+right1,count1};
    }
    if (ar[middle]>el){
        if (sizeAr%2==0)
            sizeAr=sizeAr-middle;
        else
            sizeAr=sizeAr-1-middle;
        return binSearch(ar,sizeAr,el);
    }
    if (ar[middle]<el){
        right1+=middle+1;
        for (int i=0;i<middle;i++){
            int c=ar[i];
            ar[i]=ar[middle+1+i];
            ar[middle+1+i]=c;

        }

        sizeAr=sizeAr-middle-1;

        return binSearch(ar,sizeAr,el);

    }
}


//task3
//task4
//task5

