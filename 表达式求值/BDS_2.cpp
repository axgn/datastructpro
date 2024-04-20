#include<iostream>
#include<string>
#include<stack>
#include<unordered_map>

using namespace std;

typedef int (*fun) (int,int);
int sum(int l, int r);
int deline(int l, int r);
int devide(int l, int r);
int product(int l, int r);
unordered_map<char, fun> map = {
	{'+', sum},
	{ '-', deline },
	{ '*',product},
	{ '/',devide},
};


int sum(int l, int r)
{
	return l + r;
}

int deline( int l, int r)
{
	return l - r;
}

int devide( int l, int r)
{
	return l / r;
}

int product(int l, int r)
{
	return l * r;
}

int priority(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return -1;
}

int process_op(stack<int>& st, char op) // 用于计算后缀表达式
{  
	int r = st.top();
	st.pop();
	int l = st.top();
	st.pop();
	if (r == 0 && op == '/')
	{
		return -1;
	}
	else if (map.find(op) != map.end())
	{
		st.push(map[op](l, r));
		return 0;
	}
	else
	{
		return -1;
	}
}

int evaluate(const string& s) { 
	stack<int> st;
	stack<char> op;
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == ' ') continue;

		if (s[i] == '(') {
			op.push('('); 
		}
		else if (s[i] == ')') {  
			while (op.top() != '(') {
				if (process_op(st, op.top()))
				{
					cout << "There was an error in the calculation" << "\n";
					return -1;
				}
				op.pop();  
			}
			op.pop();               
		}
		else if (map.find(s[i]) != map.end()) {
			char cur_op = s[i];
			while (!op.empty() && priority(op.top()) >= priority(cur_op)) {
				if (process_op(st, op.top()))
				{
					cout << "There was an error in the calculation" << "\n";
					return -1;
				}
				op.pop();  
			}
			op.push(cur_op);  
		}
		else {
			int number = 0;
			while (i < (int)s.size() && isalnum(s[i]))
				number = number * 10 + s[i++] - '0';
			--i;
			st.push(number);
		}
	}

	while (!op.empty()) {
		if (process_op(st, op.top()))
		{
			cout << "There was an error in the calculation" << "\n";
			return -1;
		}
		op.pop();
	}
	return st.top();
}

bool check(const string& s)
{
	for (auto& i : s)
	{
		if ((i < '0' || i > '9') && i != '*' && i != '-' && i != '+'
			&& i != '/' && i != '(' && i != ')' && i != ' ')
		{
			return false;
		}
	}
	return true;
}