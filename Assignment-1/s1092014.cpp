#include <iostream>
#include <cstdlib>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

int priority(char);//�B��l�u���v 
string InfixToPostfix(string);//�������� 
int calculate(string);//�p�� 

int main(){
	string infix;
	cout << "�п�J���ǹB�⦡�G";
	cin >> infix;
	cout << "�ӹB�⦡����Ǫ�ܪk���G" << InfixToPostfix(infix) << endl;
	cout << "�ӹB�⦡���Ȭ��G" << calculate(InfixToPostfix(infix));
	return 0;
}

int priority(char op){
	if(op=='+'||op=='-')
	{return 1;}
	else if(op=='*'||op=='/'||op=='%')
	{return 2;}
	else 
	{return 0;}
}

string InfixToPostfix(string s){
	stack<char> stack;
	string result;
	for (int i = 0; i < s.length(); i++){
        char c = s[i];
        if(c>='0'&&c<='9') //�J��B�⤸ ������X 
        {
        	result += c;
        	if(i != s.length())
        	{
        		if(s[i+1]<'0'||s[i+1]>'9')
        		{
        			result += " ";
				}
			}	
		}
		else if(c=='(') //�J��W�A�� push
		{
			stack.push('(');
		}
		else if(c==')') //�J��U�A�� pop�ܤW�A�� 
		{
			while(stack.top()!='(')
			{
				result += stack.top();
				result += " ";
				stack.pop();
			}
			stack.pop();
		}
		else //�J��B��l 
		{
			while(!stack.empty() && priority(c) <= priority(stack.top())) //�P�_stack�O�_����+�P�_Ū�쪺��ƻPtop���u������
			{
				result += stack.top(); //top�u���v�� pop���᭫�ƧP�_ 
				result += " ";
                stack.pop();
			}
			stack.push(c); //Ū�쪺����u���v�� push 
		}
	}
	while (!stack.empty()) //�Ѿlpop 
	{
        result += stack.top();
        result += " ";
        stack.pop();
    }
    return result;
}

int calculate(string postfix)
{
	stack<int> stack;
	for(int i = 0; i < postfix.length(); i++)
	{
		char c = postfix[i];
		if(c!=' ')
		{
			string input;
			if(c>='0'&&c<='9') //�J��B�⤸push 
			{
				input = c;
				while(postfix[i+1]>='0'&&postfix[i+1]<='9') //�J����ƥH�W 
				{
					input += postfix[i+1];
					i++;
				}
				
				int num;
				stringstream obj; //string to int
				obj << input;
				obj >> num;
				stack.push(num);
			}
			else if(c=='+') //�J��B��l pop�X��ӼƦr�íp�� �Apush�䵲�G
			{
				int temp1,temp2;
				temp1 = stack.top();
				stack.pop();
				temp2 = stack.top();
				stack.pop();
				stack.push(temp2+temp1);
			}
			else if(c=='-')
			{
				int temp1,temp2;
				temp1 = stack.top();
				stack.pop();
				temp2 = stack.top();
				stack.pop();
				stack.push(temp2-temp1);
			}
			else if(c=='*')
			{
				int temp1,temp2;
				temp1 = stack.top();
				stack.pop();
				temp2 = stack.top();
				stack.pop();
				stack.push(temp2*temp1);
			}
			else if(c=='/')
			{
				int temp1,temp2;
				temp1 = stack.top();
				stack.pop();
				temp2 = stack.top();
				stack.pop();
				stack.push(temp2/temp1);
			}
			else if(c=='%')
			{
				int temp1,temp2;
				temp1 = stack.top();
				stack.pop();
				temp2 = stack.top();
				stack.pop();
				stack.push(temp2%temp1);
			}
		}
	}
	return stack.top();
}
