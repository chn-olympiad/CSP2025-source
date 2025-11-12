#include<bits/stdc++.h>
using namespace std;
int n;
struct r{
	int a;
	int b;
	int c;
}w[10005];
int db(int x,int y,int z)
{
	
	if(x>y&&x>z)
	{
		return x;
	}
	else if(y>x&&y>z)
	{
		return y;
	}
	else
	{
		return z;
	}
}
int z[1005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int m;
		cin>>m;
		int d=0;
		for(int j=1;j<=m;j++)
		{
			cin>>w[j].a >>w[j].b>>w[j].c ; 
		    d=d+db(w[j].a,w[j].b,w[j].c);	
		}
		z[i]=d;
	}
	for(int i=0;i<n;i++)
	{
		cout<<z[i]<<endl;
	}
	return 0;
}
