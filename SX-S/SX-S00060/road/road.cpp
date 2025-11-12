#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int t,n,a[N],h,k;
int s[N][3],b[12][N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		cin>>s[i][0]>>s[i][1]>>s[i][2];
		h+=s[i][2];
	}
	for(int i=0;i<k;i++)
	{
		cin>>b[i][0];
		for(int j=0;j<n;j++)
		{
			cin>>b[i][j]
		}
	}
	for(int i=0;i<k;i++)
	{
		if(b[i][0]==0)
		{
			continue;
		}else{
		t=1
		}
	}
	if(t)
	{
		cout<<h;
	}else{
		cout<<0;
	}
	return 0;
}