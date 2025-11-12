#include<bits/stdc++.h>
using namespace std;
bool cmp(int t,int w)
{
	return t>w;
}
int n,m,k,d,i,j,a[110],c[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
		cin>>a[i];
	k=a[1];
	d=0;
	sort(a+1,a+1+(n*m),cmp);
	for(j=1;j<=m;j+=2)
	{
		for(i=1;i<=n;i++)
		{
			d++;c[i][j]=a[d];
			if(a[d]==k)
				cout<<j<<" "<<i,exit(0);
		}
		j++;
		for(i=n;i>=1;i--)
		{
			d++;c[i][j]=a[d];
			if(a[d]==k)
				cout<<j<<" "<<i,exit(0);
		}
	}
	if(m%2==1)
	{
		for(i=1;i<=n;i++)
		{
			d++;c[i][m]=a[d];
			if(a[d]==k)
				cout<<m<<" "<<i,exit(0);
		}
	}
}
