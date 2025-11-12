#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct node{
	int mx,mxid,mn,mnid;
}a[100000+5];
int vis[3+5];

bool cmp(node aa,node bb){
	return aa.mn<bb.mn;
}

int main()
{
	int T;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		int n;
		scanf("%d",&n);
		int x,y,z;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			if(x>=y){
				if(y>=z){//x>y>z
					a[i].mx=x;
					a[i].mxid=1;
					a[i].mn=x-y;
					a[i].mnid=2;
				}
				else if(x>=z){//x>z>y
					a[i].mx=x;
					a[i].mxid=1;
					a[i].mn=x-z;
					a[i].mnid=3;
				}
				else{//z>x>y
					a[i].mx=z;
					a[i].mxid=3;
					a[i].mn=z-x;
					a[i].mnid=1;
				}
			}
			else{//y>x
				if(x>=z){//y>x>z
					a[i].mx=y;
					a[i].mxid=2;
					a[i].mn=y-x;
					a[i].mnid=1;
				}
				else if(y>=z){//y>z>x
					a[i].mx=y;
					a[i].mxid=2;
					a[i].mn=y-z;
					a[i].mnid=3;
				}
				else{//z>y>x
					a[i].mx=z;
					a[i].mxid=3;
					a[i].mn=z-y;
					a[i].mnid=2;
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			vis[a[i].mxid]++;
			ans+=a[i].mx;
		}
		for(int j=1;j<=3;j++){
			if(vis[j]>n/2){
				sort(a+1,a+n+1,cmp);
				int s=vis[j];
				for(int i=1;i<=n;i++){
					if(a[i].mxid==j)
					{
						ans-=a[i].mn;
						s--;
						if(s<=n/2){
							break;
						}
					}
				}
				break;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
