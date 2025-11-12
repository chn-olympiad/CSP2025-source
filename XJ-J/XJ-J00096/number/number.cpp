#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char ch[N],nu[N];
int cmp(char x,char y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,i,j,k,len,cnt=0;
	cin>>ch;
	len=strlen(ch);
	for(i=0;i<len;i++)
	{
		if(ch[i]>='0' && ch[i]<='9')
		{
			nu[++cnt]=ch[i];
		}
	}
	sort(nu+1,nu+cnt+1,cmp);
	for(i=1;i<=cnt;i++)
	{
		cout<<nu[i];
	}
	return 0;
} 
