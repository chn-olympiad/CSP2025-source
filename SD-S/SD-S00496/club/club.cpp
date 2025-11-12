#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
using namespace std;
int T,n,maxn=0,maxn1=0,maxn2=0,ans=0;
const int N=1e5+10;
int vis[4][N],a[N],b[N],c[N];
int main()
{	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(a,0,sizeof(0));
		cin>>n;
		int sum=0,cnt1=1,ans1=1,cnt2=1,ans2=1,cnt3=1,ans3=1;
		maxn=maxn1=maxn2=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i]&&a[i]>c[i])
			{
				if(maxn>0)
				{
					maxn--;
					sum+=a[i];
					vis[1][cnt1]=i;
					cnt1++;
				}
				else
				{
					if(sum+max(b[i],c[i])<sum+a[i]-a[vis[1][ans1]]+max(b[vis[1][ans1]],c[vis[1][ans1]]))
					{
						sum=sum+a[i]-a[vis[1][ans1]]+max(b[vis[1][ans1]],c[vis[1][ans1]]);
						vis[1][cnt1]=i;
						cnt1++;
						ans1++;
					}
					else
					{
						sum=sum+max(b[i],c[i]);
					}
				}
			}
			else if(b[i]>a[i]&&b[i]>c[i])
			{
				if(maxn1>0)
				{
					maxn1--;
					sum+=b[i];
					vis[2][cnt2]=i;
					cnt2++;
				}
				else
				{
					if(sum+max(a[i],c[i])<sum+b[i]-b[vis[2][ans2]]+max(a[vis[2][ans2]],c[vis[2][ans2]]))
					{
						sum=sum+b[i]-b[vis[2][ans2]]+max(a[vis[2][ans2]],c[vis[2][ans2]]);
						vis[2][ans2]=i;
						cnt2++;
						ans2++;
					}
					else
					{
						sum=sum+max(a[i],c[i]);
					}
				}
			}
			else if(c[i]>a[i]&&c[i]>b[i])
			{
				if(maxn2>0)
				{
					maxn2--;
					sum+=c[i];
					vis[3][cnt3]=i;
					cnt3++;
				}
				else
				{
					if(sum+max(a[i],b[i])<sum+c[i]-c[vis[3][ans3]]+max(a[vis[3][ans3]],b[vis[3][ans3]]))
					{
						sum=sum+c[i]-c[vis[3][ans3]]+max(a[vis[3][ans3]],b[vis[3][ans3]]);
						vis[3][ans3]=i;
						cnt3++;
						ans3++;
					}
					else
					{
						sum=sum+max(a[i],b[i]);
					}
				}
			}	
		}
		cout<<sum<<endl;
	}
	return 0;
}
 
