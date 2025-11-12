#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[2000];
int n,m;
int tot;
int R;
int Rw;
bool cmp(int A,int B)
{
	return A>B;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[++tot];
		}
	}
	R=a[1];
	sort(a+1,a+tot+1,cmp);
	for(int i=1;i<=tot;i++)
	{
		if(a[i]==R)
		{
			Rw=i;
			break;
		}
	}
	int hang,lie;
	lie=(Rw+n-1)/n;
	if(lie%2==1)
	{
		hang=(Rw-(lie-1)*n);
	}
	else
	{
		hang=n+1-(Rw-(lie-1)*n);
	}
	cout<<lie<<' '<<hang;
	return 0;
}
