#include<bits/stdc++.h>
using namespace std; 
string a[500005],b[500005];
long long sum=0;
long long pdd(string l1,string l2,long long t)
{
	for(long long i=t;i<=t+l1.size();i++)
		if(l2[i]!=l1[i]) return 0;
	return 1;
}
long long th(long long t,string l1,string l2)
{
	for(int i=t;i<=t+l1.size();i++)
		l2[i]=l1[i];
	if(l2==l1) return 1;
	return 0;
}
long long pd(string l3,string l4,string l1,string l2)
{
	if(l2.size()!=l1.size())
	{return 0;}
	for(long long i=1;i<=l2.size()-l1.size();i++)
		if(pdd(l3,l1,i)&&pdd(l4,l2,i))
			if(th(i,l1,l2)==1) sum++;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string l1,l2;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	for(int i=1;i<=q;i++)
	{
		sum=0;
		cin>>l1>>l2;
		for(long long i=1;i<=n;i++)
			pd(a[i],b[i],l1,l2);
		cout<<sum<<endl;
	}
	
	return 0;
}
