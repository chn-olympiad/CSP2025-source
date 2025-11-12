#include<bits/stdc++.h>
using namespace std;
const int MAXN=15;
int n,m;
int r;
int a[MAXN*MAXN];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) 
	{
		cin>>a[i];
		if(i==1) r=a[1];
	}
	sort(a+1,a+(n*m)+1,[](int a,int b)
	{
		return a>b;
	});

	
	int w=1;
	for(int i=1;i<=n*m;i++) if(a[i]==r)
	{
		w=i;
		break;
	}
//	cout<<w<<endl;
	int l=(w+n-1)/n,h;
	if(l&1)
	{
		h=w-(l-1)*n;
	}else
	{
		h=n-(w-(l-1)*n)+1;
	}
	cout<<l<<" "<<h<<endl;
	return 0;
}

/*
2 2
98 99 100 97
*/
