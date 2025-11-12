#include <bits/stdc++.h>
using namespace std;

struct node(int x,int y) 
{
	int cj;
}a[1000001];
bool cmp(node x,node y)
{
	return x.cj>y.cj;
 } 
int main()
{
	int n,m;
	cin >> n >> m;
	int a[1000001];
	for(int i =1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	int l,h;
	int  R= a[1]; 
	sort(a+1,a+n*m+1,cmp);
	return 0;
 } 
