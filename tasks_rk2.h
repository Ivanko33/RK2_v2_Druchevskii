#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <vector>
#include <utility>
#include <functional>
#include <iterator>
#include <string>
#include <cstring>

using namespace std;

//task1
struct Node {
    Node();
    Node(int nameNode);
    ~Node();

    Node* parent;
    std::list<Node*> listChilds;
    int name;
    static int countNodes;
};

class Graph {
    private :
        Node* head;
        //здесь можно писать любые функции, которые могут понадобиться
    public :
        Graph();
        Graph(int countNodes);
        ~Graph();
        /*
            output		:	-1 - если функция не реализована
                        :	положительное число -- число узлов
            author		:
            date		:
            version		:
        */
        int buildTreeBFS(int countNodes);
        /*
            output		:	-1 - если функция не реализована
                        :	положительное число -- число узлов
            author		:
            date		:
            version		:
        */
        int buildTreeDFS(int countNodes);
        /*
            description	:	обход графа и записи вершин в файл
            input		:
            output		:
            author		:
            date		:
            version		:
        */
        void BFS();
        void DFS();
        /*
            description	:	функция поиска узла по его имени,
                            DFS - № студ билет чётный
                            BSD - № студ билет нечётный
            input 		:	nameNode -- имя узла
            output		:	{bool -- узел найде, list<int> -- список имён узлов до необходимого}
            description	:	приставка DFS -- поиск в глубину, BSF -- поиск в ширину
            author		:
            date		:
            version		:
        */
        std::pair<bool, list<int>> searchDFS(int nameNode);
        std::pair<bool, list<int>> searchBFS(int nameNode);
};

//task2
pair<int/*index el*/,int /*count call*/> binSearch(int* ar, int sizeAr, int el);

//task3
template<class T>
class Filo {
    private :
        T* ar;	//массив
        int size;	//размер массива
        int countData;	//число элементов в массиве
    public :
        Filo() {

        }
        Filo(int _size) {
            size=_size;
            countData=0;
            ar=new T [_size];
        }
        ~Filo() {
            size=0;
            countData=0;
            delete[] ar;
        }

        int push_back(T el) {
            if(countData>size-1)
                return 0;
            if (ar==nullptr)
                ar=new T();

            ar[countData]=el;
            countData++;
            return 1;
        }

        pair<int,T> pop_back() {
            if (countData<1)
                return {0,0};
            if (ar==nullptr)
                ar=new T();
            countData--;
            return {1,ar[countData]};
        }


        void returnAr() {}
};

//task4

template <typename T>

ostream & operator <<(ostream & os, const pair<int,T> t){
    os<<"("<<t.first<<" , "<<t.second<<")"<<"\n";
    return os;
}


//task5
template<class T>
class CheckBrackets : public Filo<char> {
private:
    //можно объявляеть любые переменные и функции
public :
    CheckBrackets() : Filo<char>() { }
    ~CheckBrackets() {}
    /*
        input		:	строка со скобками
        output		:	0 - всё хорошо, -1 - скобок не хватает
        description	:	проверка скобок
    */
    int checkBrackets(const char* strBrackets) {
        for (int i=0;strBrackets[i]!=NULL;i++){

           if (strBrackets[i]=='(')
                push_back(strBrackets[i]);
            if (strBrackets[i]=='[')
                push_back(strBrackets[i]);
            if (strBrackets[i]=='{')
                push_back(strBrackets[i]);
            if (strBrackets[i]==')'){

                if (pop_back().second!='('){
                    return -1;
                }
            }
            if (strBrackets[i]=='}'){

                if (pop_back().second!='{'){
                    return -1;
                }
            }
            if (strBrackets[i]==']'){
                if (pop_back().second!='['){
                    return -1;
                }
            }
        }
        if (pop_back().first!=0)
            return -1;
        return 0;
    }
};
