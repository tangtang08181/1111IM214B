#include <iostream>
#include <cstdlib>
using namespace std;
#define Max 100

int heap[Max];
int size = 0;

void Insert(int num)
{
	if(++size >= Max) //�P�_��ƬO�_�W�X�W�� 
	{ //�O 
		cout << "��ƶW�X�W��\n";
	}
	else
	{ //�_ 
		int i = 0; //����hole
		i = size;
		
		while(i > 1) //�վ���
		{
			if(num <= heap[i/2]) //hole��parent > num�ɡA����վ� 
			{
				break;
			}
			else //hole��parent < num�ɡAhole�W��
			{
				heap[i] = heap[i/2];
				i = i/2;
			}
		}
		heap[i] = num; //num��Jhole 
		//cout << i << "  " << heap[i] << endl;
	}
}
void DeleteMax()
{
	int parent, child, temp;
	
	if(size == 0)
	{
		cout << "�L��Ʀs�b" << endl;
	}
	else
	{
		cout << "�R��" << heap[1] << endl; 
		temp = heap[size--]; //�x�s��n���̫᪺�ȨçR�� 
		parent = 1; //hole����m 
		child = 2; //��child����m 
		while (child <= size) //�P�_child�O�_�b��n���d�� 
		{
			if((child < size) && (heap[child] < heap[child+1])) //�P�_���kchild���j�p 
			{
				child++; //���j��child���i��n������child 
			}
			if(temp >= heap[child]) //�̫᪺�Ȥ�child�j�N���δ��F 
			{
				break;
			}
			heap[parent] = heap[child]; //�U��hole�A�P���j��child���洫 
			parent = child;
			child = child*2; //child���U�@�h�A�i���� 
		}
		heap[parent] = temp; //�̫᪺�ȩ�Jhole 
	}
}
void PrintHeap()
{
	if(size == 0)
	{
		cout << "�L��Ʀs�b" << endl;
	}
	else
	{
		cout << "===================" << endl;
		for(int i = 1;i <= size;i++)
		{
			cout << "��" << i <<"�Ӱ�n:  " << heap[i] << endl;
		}
		cout << "===================" << endl;
	}
}

int main(){
	int num,input;
	do{
		system("cls"); //�M�� 
		cout << "*******************" << endl;
		cout << "1.�s�W" << endl;
		cout << "2.�R���̤j" << endl;
		cout << "3.�C�L��Ӱ�n" << endl;
		cout << "4.����" << endl;
		cout << "*******************" << endl;
		cout << "�п�J����{��:";
		cin >> input;
		cout << endl;
		
		switch(input)
		{
			case 1 : 
				cout << "��J0����s�W\n" << endl;
				do{
					cout << "�s�W����:";
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
				cout <<"\n��J���~�A�Э��s��J\n" << endl;
				system("pause");
				break;
		}
	} while(input != 4);
}
