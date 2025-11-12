#include<bits/stdc++.h>
using namespace std;
int sum[20];//Í°ÅÅĞò 
int n;
string st;
char ch;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,st);
	int n=st.size();
	for(int i=0;i<n;i++)
	{
		if('0'<=st[i]&&st[i]<='9')
		{
			sum[(int)(st[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=sum[i];j++)
		{
			cout<<i;	
		}
	}
	cout<<"\n";
	return 0;
}
