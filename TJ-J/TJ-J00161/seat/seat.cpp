#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[11][11];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		} 
	}
	int r=a[1][1];
	int t[121];
	int num=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			num++;
			t[num]=a[i][j];
		} 
	}
	int ans[121];
	for(int i=1;i<=num;i++)
	{
		int maxn=0;
		for(int j=1;j<=num;j++)
		{
			if(t[j]!=-1)
			{
				if(t[j]>maxn)
				{
					maxn=t[j];
				}
			}
		}
		ans[i]=maxn;
		for(int j=1;j<=num;j++)
		{
			if(t[j]==maxn)
			{
				t[j]=-1;
				break;
			} 
		}
	}
	int tan=0;
	for(int i=1;i<=num;i++)
	{
		if(ans[i]==r)
		{
			tan=i; 
		}
	}
	int b=tan/n;
	int v=tan%n;
	if(b==0&&v==1)
	{
		cout<<1<<" "<<1;
		return 0;
	} 
	b+=1;
	if(v==0&&b<=n)
	{
		cout<<1<<" "<<b;
		return 0;
	}
	if(b%2==0)
	{
		cout<<n-(v-1)<<" "<<b;
	}
	else
	{
		cout<<b<<" "<<n-(v+1);
	}
	return 0;
}

