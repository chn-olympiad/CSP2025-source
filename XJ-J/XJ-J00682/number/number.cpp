#include<bits/stdc++.h>
using namespace std;
int a[190000000];  
int f_fun(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int e=0,w;
	bool p=true;
	cin>>s;
	for(int j=0;j<s.size();j++)
	{
		if(s[j]>='0'&&s[j]<='9')
		{
			a[e]=(int)s[j]-'0';
			e++;
		}
	}
	
	sort(a+0,a+e,f_fun);
for(int i=0;i<e;i++)cout<<a[i];
		

	return 0;	
}
