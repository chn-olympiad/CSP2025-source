#include<bits/stdc++.h>
#define endl '\n'
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define freio(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout);
using namespace std;
char a[1000005];
int b[1000005];
int lena;
int lenb;
bool cmp(int x,int y)
{
	if(x>y)
	{
		return true;
	}
	return false;
}
//RP++
//8:45 100
int main()
{
	fastio
	freio("number")
	cin>>a;
	lena=strlen(a);
//	cout<<lena<<endl;
	for(int i=0;i<lena;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
//			cout<<a[i]<<" ";
			b[++lenb]=int(a[i]-'0');
		}
	}
//	cout<<lenb;
//	for(int i=1;i<=lenb;i++)
//	{
//		cout<<b[i];
//	}
	sort(b+1,b+lenb+1,cmp);
	for(int i=1;i<=lenb;i++)
	{
		cout<<b[i];
	}
	return 0;
}