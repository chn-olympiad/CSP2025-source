//余俊辰 SN-J00045 西安市曲江第一学校 
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char c[N];
int a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string x;
	cin>>x;
	for(int i=0;i<N;i++)a[i]=-1;
	for(int i=0;i<x.size();i++)
	{
		if(x[i]>='0'&&x[i]<='9')a[i]=x[i]-'0';
	}
	sort(a,a+x.size());
	for(int i=x.size()-1;i>=0;i--)
	{
		if(a[i]==-1)break;
		else cout<<a[i];
	}
	return 0;
}

