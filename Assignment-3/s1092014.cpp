#include<iostream> 
#include<fstream>
using namespace std;
#define MAX_VERTICES 7 //相鄰矩陣大小固定為7*7 
#define INT_MAX 10000 //(表示無限大)

int choose(int distance[], int n, int found[]) //貪婪演算法 
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++) {
		if(distance[i] < min && found[i]==0) //挑距離最短且未走過 
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
		found[i] = 0; //found=0表示未走過 
		distance[i] = INT_MAX; //路徑無限大 
	}
	//found[v] = 1; //出發點已走過 (利用下方迴圈走過出發點並判斷u)
	distance[v]=0; //出發點路徑為0

	for(i = 0; i < n-1; i++) {
		u = choose(distance,n,found); //挑距離最短且未走過 	
		//cout << "u:" << u << endl;
		found[u] = 1; //走過u 
		for(w = 0; w < n; w++)
		{
			if (found[w]==0) //w未走過 
			{
				//cout << "cost[" << u << "]["<< w <<"]:" << cost[u][w] << endl; 
				if (distance[u] + cost[u][w] < distance[w] && cost[u][w]!=0) //u的路徑+u到w的路徑<原w的路徑 
				{
					distance[w] = distance[u] + cost[u][w]; //取代 
					//cout << "distance[" << w << "]:" <<distance[w] << endl; 
				} 
			}
		}
	}
	
	for(int w = 0;w < n;w++)
	{
		cout << "出發點" << v << "到" << w << "的最短路徑為:" << distance[w] << endl;
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
	cout << "出發點:";
	cin >> n; 
	shortestPath(n,matrix);
	return 0;
}
