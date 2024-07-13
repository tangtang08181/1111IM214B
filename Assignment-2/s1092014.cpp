#include <iostream>
#include <cstdlib>
using namespace std;
#define Max 100

int heap[Max];
int size = 0;

void Insert(int num)
{
	if(++size >= Max) //判斷資料是否超出上限 
	{ //是 
		cout << "資料超出上限\n";
	}
	else
	{ //否 
		int i = 0; //產生hole
		i = size;
		
		while(i > 1) //調整資料
		{
			if(num <= heap[i/2]) //hole的parent > num時，停止調整 
			{
				break;
			}
			else //hole的parent < num時，hole上移
			{
				heap[i] = heap[i/2];
				i = i/2;
			}
		}
		heap[i] = num; //num放入hole 
		//cout << i << "  " << heap[i] << endl;
	}
}
void DeleteMax()
{
	int parent, child, temp;
	
	if(size == 0)
	{
		cout << "無資料存在" << endl;
	}
	else
	{
		cout << "刪除" << heap[1] << endl; 
		temp = heap[size--]; //儲存堆積中最後的值並刪除 
		parent = 1; //hole的位置 
		child = 2; //左child的位置 
		while (child <= size) //判斷child是否在堆積的範圍內 
		{
			if((child < size) && (heap[child] < heap[child+1])) //判斷左右child的大小 
			{
				child++; //較大的child為可能要替換的child 
			}
			if(temp >= heap[child]) //最後的值比child大就不用換了 
			{
				break;
			}
			heap[parent] = heap[child]; //下移hole，與較大的child做交換 
			parent = child;
			child = child*2; //child往下一層再進行比較 
		}
		heap[parent] = temp; //最後的值放入hole 
	}
}
void PrintHeap()
{
	if(size == 0)
	{
		cout << "無資料存在" << endl;
	}
	else
	{
		cout << "===================" << endl;
		for(int i = 1;i <= size;i++)
		{
			cout << "第" << i <<"個堆積:  " << heap[i] << endl;
		}
		cout << "===================" << endl;
	}
}

int main(){
	int num,input;
	do{
		system("cls"); //清除 
		cout << "*******************" << endl;
		cout << "1.新增" << endl;
		cout << "2.刪除最大" << endl;
		cout << "3.列印整個堆積" << endl;
		cout << "4.結束" << endl;
		cout << "*******************" << endl;
		cout << "請輸入執行程序:";
		cin >> input;
		cout << endl;
		
		switch(input)
		{
			case 1 : 
				cout << "輸入0停止新增\n" << endl;
				do{
					cout << "新增的值:";
					cin >> num;
					cout << endl;
					
					if(num != 0)
					{
						Insert(num);
					}
				} while(num != 0);
				system("pause");
				break;
			case 2 :
				DeleteMax();
				system("pause");
				break;
				
			case 3 :
				PrintHeap();
				system("pause");
				break;
				
			case 4 : 
				return 0;
			
			default:
				cout <<"\n輸入錯誤，請重新輸入\n" << endl;
				system("pause");
				break;
		}
	} while(input != 4);
}
