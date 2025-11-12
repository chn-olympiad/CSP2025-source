#include<bits/stdc++.h>
using namespace std;
int n,flag,cnt,sum;
long long ans=0;
struct node {
	int x,y,z,h;
} a[100005];
bool cmp(node q,node w)
{
	return q.h<w.h;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		ans=0;
		memset(a,0,sizeof(a));
		cin>>n;
		flag=cnt=sum=0;
		for(int i=1; i<=n; i++) {
			scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].x>=max(a[i].y,a[i].z)) {
				flag++,ans+=a[i].x;
				a[i].h=a[i].x-max(a[i].y,a[i].z);
			} else if(a[i].y>=max(a[i].y,a[i].z)) {
				cnt++,ans+=a[i].y;
				a[i].h=a[i].y-max(a[i].x,a[i].z);
			} else {
				sum++,ans+=a[i].z;
				a[i].h=a[i].z-max(a[i].y,a[i].x);
			}
		}
		sort(a+1,a+n+1,cmp);
		if(flag>n/2) {
			int o=0;
			for(int i=1;i<=n;i++)
			{
				if(o==flag-n/2)
					break;
				if(a[i].x>=max(a[i].y,a[i].z))
				{
					ans-=a[i].h;
					o++;
				}
			}
		} else if(cnt>n/2) {
			int o=0;
			for(int i=1;i<=n;i++)
			{
				if(o==cnt-n/2)
					break;
				if(a[i].y>=max(a[i].x,a[i].z))
				{
					ans-=a[i].h;
					o++;
				}
			}
		} else if(sum>n/2) {
			int o=0;
			for(int i=1;i<=n;i++)
			{
				if(o==sum-n/2)
					break;
				if(a[i].z>=max(a[i].x,a[i].y))
				{
					ans-=a[i].h;
					o++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
