#include<iostream>
using namespace std;
int n,k,idx=0;
int a[500005]; 
int f[21][500005];
int kk[25];
int lenax,ans=0;
void bfs(int sum,int step)
{
	if(step>=n)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=step+1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int t=1;
			for(int p=1;p<=lenax;p++)
			{
				int ana;
				ana=f[p][j]-f[p][i-1];
				ana=ana%2;
//				cout<<p<<" "<<j<<" "<<i<<" "<<f[p][j]<<" "<<f[p][i-1]<<" "<<ana<<" "<<kk[p]<<endl;
				if(ana!=kk[p])
				{
					t=0;
					break;
				}
//				cout<<p<<" "<<j<<" "<<" "<<i<<" "<<f[p][j]<<" "<<f[p][i-1]<<endl;
//				if(i==2&&j==4)
//				{
//					cout<<ana<<" "<<t;
//				}
			}
			
			if(t)
			{
				bfs(sum+1,j);
			}
			
		}
	}
	return;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int idx=0;
	while(k)
	{
		int x;
		x=k%2;
		idx++;
		kk[idx]=x;
		k=k/2;
	}
	lenax=idx;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		idx=0;
		int x=a[i],y;
		while(x)
		{
			y=x%2;
			idx++;
			f[idx][i]=f[idx][i-1]+y;
			x=x/2;
			lenax=max(lenax,idx);
		}
		for(int j=1;j<=lenax;j++)
		{
			if(!f[j][i]) f[j][i]=f[j][i-1];
//			cout<<j<<" "<<i<<" "<<f[j][i]<<endl;
		}
	}
	bfs(0,0);
	cout<<ans<<endl;
	return 0;
} 
