#include<bits/stdc++.h>
#define max(a,b) (a>b?a:b)
#define int long long
using namespace std;
int t,n,mx[3],ans,tot,b[114514];
struct node{
	int x,y,z,mx;
}a[114514];
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	return x*f;
}
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	for(;t;t--){
		n=read();mx[0]=mx[1]=mx[2]=ans=0;
		for(int i=1;i<=n;i++){
			a[i].x=read();a[i].y=read();a[i].z=read();
			if(a[i].x>=max(a[i].y,a[i].z))ans+=a[i].x,mx[0]++,a[i].mx=0;
			else if(a[i].y>=max(a[i].x,a[i].z))ans+=a[i].y,mx[1]++,a[i].mx=1;
			else ans+=a[i].z,mx[2]++,a[i].mx=2;
		}tot=0;
		if(mx[0]>n/2)for(int i=1;i<=n;i++)if(a[i].mx==0)b[++tot]=a[i].x-max(a[i].y,a[i].z);
		if(mx[1]>n/2)for(int i=1;i<=n;i++)if(a[i].mx==1)b[++tot]=a[i].y-max(a[i].x,a[i].z);
		if(mx[2]>n/2)for(int i=1;i<=n;i++)if(a[i].mx==2)b[++tot]=a[i].z-max(a[i].x,a[i].y);
		sort(b+1,b+tot+1,cmp);
		for(int i=max(mx[0],max(mx[1],mx[2]));i>n/2;i--)ans-=b[i];
		cout<<ans<<'\n';
	}
	return 0;
}