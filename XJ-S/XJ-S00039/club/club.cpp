#include<bits/stdc++.h>
using namespace std;
int n,sum[11]={0};
struct node{
	int a1;
	int a2;
	int a3;
	int s;
}a[100001];
bool cmp(node x,node y)
{
	if(x.s>y.s) return x.s>y.s;
	else return x.s<y.s;
}
int dp[100001][4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int T=1;T<=t;T++)
	{
		cin>>n;
		int w[4]={0};
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a[i].s=a[i].a1+a[i].a2+a[i].a3;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			if((w[1]==n/2 && w[2]==n/2 && w[3]==n/2)||w[1]+w[2]==n-w[3]) break;
			else{
			int maxn=max(a[i].a1,max(a[i].a2,a[i].a3));
			if(maxn==a[i].a1){
				if(w[1]<n/2)
				{
					w[1]++;
					sum[T]+=maxn;
				}
				else
				{
					maxn=max(a[i].a2,a[i].a3);
					if(w[2]<n/2)
					{
						w[2]++;
						sum[T]+=maxn;
					}
					else
					{
						maxn=a[i].a3;
						w[3]++;
					}
				}
			}
			if(maxn==a[i].a2){
				if(w[2]<n/2)
				{
					w[2]++;
					sum[T]+=maxn;
				}
				else
				{
					maxn=max(a[i].a1,a[i].a3);
					if(w[1]<n/2)
					{
						w[1]++;
						sum[T]+=maxn;
					}
					else
					{
						maxn=a[i].a3;
						w[3]++;
					}
				}
			}
			if(maxn==a[i].a3){
				if(w[3]<n/2)
				{
					w[3]++;
					sum[T]+=maxn;
				}
				else
				{
					maxn=max(a[i].a2,a[i].a1);
					if(w[2]<n/2)
					{
						w[2]++;
						sum[T]+=maxn;
					}
					else
					{
						maxn=a[i].a1;
						w[1]++;
					}
				}
			}
			}
		}
}
	for(int T=1;T<=t;T++)
	{
		cout<<sum[T]<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
 } 
