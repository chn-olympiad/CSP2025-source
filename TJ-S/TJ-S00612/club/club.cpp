#include <bits/stdc++.h>
using namespace std;
long long n,t,m=0,ct=0;
struct p{
	long long a=0,b=0,c=0;
}r[10010];
int per(int i,long long s,int aa,int bb,int cc)
{
	
	if(s>ct)
	{
		ct=s;
	}
	if(i>=n)
	{
		return 0;
	}
	if(aa+1<=m)
	{
		per(i+1,s+r[i].a,aa+1,bb,cc);
	}
	if(bb+1<=m)
	{
		per(i+1,s+r[i].b,aa,bb+1,cc);
	}
	if(cc+1<=m)
	{
		per(i+1,s+r[i].c,aa,bb,cc+1);
	}
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for(int j=0;j<t;j++)
	{
		ct=0;
		cin >> n;
		m=n/2;
		for(int i=0;i<n;i++)
		{
			cin >> r[i].a >> r[i].b >> r[i].c;
		}
		per(0,0,0,0,0);
		cout << ct << endl;
	}
	
	
	return 0;
}

