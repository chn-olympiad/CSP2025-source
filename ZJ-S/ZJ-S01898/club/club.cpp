#include<bits/stdc++.h>
using namespace std;
int t,n,k[4],h[4],l[100001],sum;
struct u
{
	int num,d;
}a[100001][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		sum=0;
		memset(k,0,sizeof(k));
		memset(a,0,sizeof(a));
		memset(l,0,sizeof(l));
		memset(h,0,sizeof(h));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j].num;
				a[i][j].d=j;
			}
			if(a[i][1].num<a[i][2].num) swap(a[i][1],a[i][2]);
			if(a[i][2].num<a[i][3].num) swap(a[i][2],a[i][3]);
			if(a[i][1].num<a[i][2].num) swap(a[i][1],a[i][2]);
			k[a[i][1].d]+=a[i][1].num;
			h[a[i][1].d]++;
		}
		sum=k[1]+k[2]+k[3];
		for(int i=1;i<=3;i++)
		{
			if(h[i]>n/2)
			{
				for(int j=1;j<=n;j++)
				{
					l[j]=a[j][1].num-a[j][2].num;
				}
				sort(l+1,l+n+1);
				for(int j=1;j<=h[i]-n/2;j++)
				{
					sum-=l[j];
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
