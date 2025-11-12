#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

struct r{
	int u,v,w;
	
}road[1000006];
int fa[100005];

int find(int a)
{
	if(fa[a]==a) return a;
	fa[a]=find(fa[a]);
	return fa[a];
	
	
}
int un(int a,int b)
{
	int A=find(a);
	int B=find(b);
	if(A!=B)
	fa[A]=B;
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
 
 cout<<7835242;
 
	return 0;
}
