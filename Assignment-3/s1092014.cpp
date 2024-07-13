#include<iostream> 
#include<fstream>
using namespace std;
#define MAX_VERTICES 7 //�۾F�x�}�j�p�T�w��7*7 
#define INT_MAX 10000 //(��ܵL���j)

int choose(int distance[], int n, int found[]) //�g���t��k 
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++) {
		if(distance[i] < min && found[i]==0) //�D�Z���̵u�B�����L 
		{
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}

void shortestPath(int v, int cost[][MAX_VERTICES])
{
	int n = MAX_VERTICES;
	int i,u,w;
	int found[MAX_VERTICES];
	int distance[MAX_VERTICES];
	for (i = 0; i < n; i++) {
		found[i] = 0; //found=0��ܥ����L 
		distance[i] = INT_MAX; //���|�L���j 
	}
	//found[v] = 1; //�X�o�I�w���L (�Q�ΤU��j�騫�L�X�o�I�çP�_u)
	distance[v]=0; //�X�o�I���|��0

	for(i = 0; i < n-1; i++) {
		u = choose(distance,n,found); //�D�Z���̵u�B�����L 	
		//cout << "u:" << u << endl;
		found[u] = 1; //���Lu 
		for(w = 0; w < n; w++)
		{
			if (found[w]==0) //w�����L 
			{
				//cout << "cost[" << u << "]["<< w <<"]:" << cost[u][w] << endl; 
				if (distance[u] + cost[u][w] < distance[w] && cost[u][w]!=0) //u�����|+u��w�����|<��w�����| 
				{
					distance[w] = distance[u] + cost[u][w]; //���N 
					//cout << "distance[" << w << "]:" <<distance[w] << endl; 
				} 
			}
		}
	}
	
	for(int w = 0;w < n;w++)
	{
		cout << "�X�o�I" << v << "��" << w << "���̵u���|��:" << distance[w] << endl;
	}
}

int main(){
	int matrix[MAX_VERTICES][MAX_VERTICES];
	ifstream InputFile("Matrix.txt");
	if(!InputFile.is_open())
	{
		cout << "error" << endl;
		return 0;
	}
	for(int i = 0;i < MAX_VERTICES;i++)
	{
		for(int j = 0;j < MAX_VERTICES;j++)
		{
			InputFile >> matrix[i][j];
		}
	}
	
	int n;
	cout << "�X�o�I:";
	cin >> n; 
	shortestPath(n,matrix);
	return 0;
}
