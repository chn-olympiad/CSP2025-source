#include<iostream>
#include<algorithm>
using namespace std;
long long sum,js[105],k=1;
bool zzz(int x,int y)
{
	if(x!=y) return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,mb,l=1,r,Z=1;
	cin>>n>>m>>mb;
	r=m;
	for(int i=1;i<=n*m-1;i++)
	{
		cin>>js[i];
	}
	sort(js+1,js+1+(n*m-1),zzz);
	if(mb>js[1])
	{
		cout<<1<<" "<<1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(k==1){
		for(int j=1;j<=m;j++)
		{
			sum++;
			if(mb>js[sum+1]&&mb<js[sum]&&sum+1<=n*m-1)
			{
				if(i==1&&j==1) j++;
				cout<<i<<" "<<j;
				return 0;
			}
		}
		k=2;
		}
	else
	{
	
		for(int j=m;j>=1;j--)
		{
			sum++;
			if(mb>js[sum+1]&&mb<js[sum]&&sum+1<=n*m-1)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
		k=1;
	}	
	}
	cout<<n<<" ";
	if(k==1) cout<<m;
	else cout<<1;
	return 0;
}

