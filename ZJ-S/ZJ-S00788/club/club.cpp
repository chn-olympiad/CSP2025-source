#include<bits/stdc++.h>
using namespace std;
const int N=100008;
#define pll pair<int,int>
int n,T;
int ans=0;
int x[N][5];
int w[5];
int s[N];

void dfs(int t,int sm)
{
	if(t>n)
	{
		ans=ans<sm?sm:ans;
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		if(w[i]<(n/2))
		{
			w[i]++;
			dfs(t+1,sm+x[t][i]);
			w[i]--;
		}
	}
	return ;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>T;
	while(T--)
	{
		cin>>n;
		ans=0;
		memset(w,0,sizeof(w));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>x[i][j];
		if(n>100)
		{
			for(int i=1;i<=n;i++)
				s[i]=x[i][1];
			sort(s+1,s+1+n,[](int a,int b){return a>b;});
			for(int i=1;i<=n/2;i++)
				ans+=s[i];
		}	
		else
			dfs(1,0);
		cout<<ans<<"\n";
	}
	cout<<endl;
	return 0;
}
