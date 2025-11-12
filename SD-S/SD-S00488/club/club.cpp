#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int a[N][5],f[N][5],c[N],b[N];
int n,sum=0;
vector <int> v[5];
int cnt[5];
priority_queue<int>q1,q2,q3;
void init(){
	for(int i=1;i<=3;i++)
	{
		v[i].clear();
		cnt[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=c[i+1];
	}
	sum=0;
	v.clear();
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
	{
	
	
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)	 
			{
				cin>>a[i][j];
				if(a[i][j]>=a[i][b[i]])
					b[i]=j;
			}
			
		}
			sum+=a[i][b[i]];
			cnt[b[i]]++;
			v[b[i]].push_back(i);
			for(int j=1;j<=3;j++)
			{
				if(j==b[i]) 
					continue;
				if(a[i][j]>a[i][c[i]])
					c[i]=j;
			}
    }
	return 0;
}      

