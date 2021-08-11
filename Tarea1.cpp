#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>

#define KRED "\x1B[31m"//RED
#define KWHT "\x1B[37m"//WHITE

using namespace std;
using Vector = vector<int>;

void setVector(Vector &stack,int N);
void InsertionSort(Vector &stack);
void SelectionSort(Vector &stack);
void printV(Vector &stack);
void printVD(Vector &stack);

int main(int argc, char const *argv[])
{
	std::chrono::time_point <std::chrono::system_clock> start,end;

	Vector stack;
	int N,op;
	cout<<"Ingrese la longitud del Vector: ";
	cin>>N;

	setVector(stack,N);
	system("cls");

	cout<<"\t\tMetodos de Ordenamiento"<<endl;
	cout<<endl;
	cout<<"\t";
	printV(stack);
	cout<<endl;
	cout<<endl;

	cout<<"\t1.-Insercion"<<endl;
	cout<<"\t2.-Seleccion"<<endl;
	cout<<"\tOpcion: "; cin>>op;

	//tiempo de ejecucion
	cout<<endl;
	start = std::chrono::system_clock::now();

	switch(op){
		case 1:
			cout<<"\t<--------------Insercion-------------->"<<endl;
			cout<<endl<<"\tVector Inicial  >> ";
			printVD(stack);
			InsertionSort(stack);
			break;
		case 2: 
			cout<<"\t<--------------Seleccion-------------->"<<endl;
			cout<<endl<<"\tVector Inicial  >> ";
			printVD(stack);
			SelectionSort(stack);
			break;
	}

	end = std::chrono::system_clock::now();

	cout<<endl<<"\tVector Ordenado >> ";
	printV(stack);
	cout<<endl;

	std::chrono::duration<double> lapso_segundos = end-start;
	cout<<endl<<"\tLapso de tiempo: "<<lapso_segundos.count()<<" s"<<endl;
	cout<<endl;
	return 0;
}

void printV(Vector &stack){
	cout<<"[";
	for (int i = 0; i < stack.size(); ++i){
		if(i == stack.size()-1){
			cout<<stack[i];
		}else{
			cout<<stack[i]<<",";
		}
	}
	cout<<"]";
}

void printVD(Vector &stack){
	printf("%s",KRED);
	cout<<"[";
	for (int i = 0; i < stack.size(); ++i){
		if(i == stack.size()-1){
			cout<<stack[i];
		}else{
			cout<<stack[i]<<",";
		}
	}
	cout<<"]";
	printf("%s",KWHT);
}

void setVector(Vector &stack,int N){
	int x;
	for (int i = 0; i < N; ++i)
	{
		cin>>x;
		stack.push_back(x);
	}
}

//Algoritmo ede ordenacion de O(n)
void InsertionSort(Vector &stack){
	int pos,aux;
	for (int i = 0; i < stack.size(); ++i)
	{
		pos = i;
		aux = stack[i];
		while( (pos>0) && stack[pos-1] > aux){
			stack[pos] = stack[pos-1];
			pos--;
		}
		stack[pos] = aux;
	}
}

//Algortimo e ordenacion de O(n^2);
void SelectionSort(Vector &stack){
	int begin,aux;						             
	for (int i = 0; i < stack.size(); ++i){           
		begin = i;                           
		for (int j = i+1; j < stack.size(); ++j){       
			if(stack[j]<stack[begin]){                 
				begin = j;                         
			}                                  		
		}
		swap(stack[i],stack[begin]);   		                   
	}    
}
