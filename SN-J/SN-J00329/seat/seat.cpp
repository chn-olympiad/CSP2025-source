//SN-J00329 zhangjiakang xi'an gaoxindiyizhongxue
#include<bits/stdc++.h>
using ll=long long;
using namespace std;
const int maxn=105;
int n,m;
int a[maxn],b[maxn];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n*m+1,cmp);
	int id=0;
	for(int i=1;i<=n*m;i++)
		if(b[i]==a[1])
		{
			id=i;
			break;
		}
	cout<<id<<endl;
	int yu=(id-1)/n,xi=(id-1)%n+1;
	if(yu%2==0)
		cout<<yu+1<<" "<<xi;
	else cout<<yu+1<<" "<<n-xi+1;
	return 0;
}/*3 3
 94 95 96 97 98 99 100 93 92*/
