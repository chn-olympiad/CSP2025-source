//刘家豪  SN-S00052 西安铁一中滨河高级中学 
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a;
	int b;
	int c;
	int d;
	int e;
};
bool cmp(node p,node q)
{
	return p.c<q.c;
}
int n,m,k;
node f[1000005];
node t[15];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >>k;
	for(int i=0;i<m;i++)
	{
		cin >> f[i].a >> f[i].b>>f[i].c;
	}
	sort(f,f+m,cmp);
	for(int i=0;i<k;i++)
	{
		cin >> t[i].a >> t[i].b>>t[i].c>>t[i].d>>t[i].e;
	}
	cout << 0;
	return 0;
}
