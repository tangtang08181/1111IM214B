#include <iostream>
#include <cstdlib>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

int priority(char);//運算子優先權 
string InfixToPostfix(string);//中序轉後序 
int calculate(string);//計算 

int main(){
	string infix;
	cout << "請輸入中序運算式：";
	cin >> infix;
	cout << "該運算式的後序表示法為：" << InfixToPostfix(infix) << endl;
	cout << "該運算式的值為：" << calculate(InfixToPostfix(infix));
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
        if(c>='0'&&c<='9') //遇到運算元 直接輸出 
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
		else if(c=='(') //遇到上括號 push
		{
			stack.push('(');
		}
		else if(c==')') //遇到下括號 pop至上括號 
		{
			while(stack.top()!='(')
			{
				result += stack.top();
				result += " ";
				stack.pop();
			}
			stack.pop();
		}
		else //遇到運算子 
		{
			while(!stack.empty() && priority(c) <= priority(stack.top())) //判斷stack是否為空+判斷讀到的資料與top的優先順序
			{
				result += stack.top(); //top優先權高 pop之後重複判斷 
				result += " ";
                stack.pop();
			}
			stack.push(c); //讀到的資料優先權高 push 
		}
	}
	while (!stack.empty()) //剩餘pop 
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
			if(c>='0'&&c<='9') //遇到運算元push 
			{
				input = c;
				while(postfix[i+1]>='0'&&postfix[i+1]<='9') //遇到兩位數以上 
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
			else if(c=='+') //遇到運算子 pop出兩個數字並計算 再push其結果
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
