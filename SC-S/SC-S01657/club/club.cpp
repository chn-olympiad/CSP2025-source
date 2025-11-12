#include<bits/stdc++.h> 
using namespace std;
const int N=1e5+5;
int a[N][4],clu[N],ps[4],n,ans;
void pr(int x,int mod)
{
	for(int i=1;i<=x;i++)
		cout<<"	";
	switch(mod)
	{
		case 1:
			cout<<"clu:";
			for(int i=1;i<=n;i++)
				cout<<clu[i]<<" ";
			cout<<endl;
			break;
		case 2:
			cout<<" ps:";
			for(int i=1;i<=3;i++)
				cout<<ps[i]<<" ";
			cout<<endl;
			break;
	}
}
int dfs(int x,int sum)
{
	if(x>n)
		return sum;
	for(int i=1;i<=3;i++)
	{
		if(ps[i]+1<=n/2)
		{
			//pr(x,0);
			//cout<<"x/i/ps[i]:"<<x<<" "<<i<<" "<<ps[i]<<endl;
			clu[x]=i;
			//pr(x,1);
			ps[i]++;
			//pr(x,2);
			sum+=a[x][i];
			//pr(x,0);
			//cout<<"sum/a[x][i]:"<<sum<<" "<<a[x][i]<<endl<<endl;
			ans=max(ans,dfs(x+1,sum));
			sum-=a[x][i];
			ps[i]--;
			//pr(x,1);
			clu[i]=0;
			//pr(x,2);
		}
	}
	return 0;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1,0);
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}