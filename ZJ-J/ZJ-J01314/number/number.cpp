#include<bits/stdc++.h>
using namespace std;
char s;
stack<char>w;
int c[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s)
	{
		if(s<='9'&&s>='0')
			w.push(s);
	}
	int num=w.size();
	for(int i=1;i<=num;i++)
	{
		c[i]=w.top()-'0';
		w.pop();
	}
	sort(c+1,c+num+1);
	for(int i=num;i>0;i++)
	{
		cout<<c[i];
	}
	
	return 0;
}
