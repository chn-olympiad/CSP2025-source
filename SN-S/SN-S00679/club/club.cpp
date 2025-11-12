#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int a,b,c;
};
node a[100005];
int ans=0,cnt=0,x,y,z,mid,dp[100005],b[100005],c[100005],a1,a2;
void dfs(int i){
	if(x>mid)
		return;
	if(y>mid)
		return;
	if(z>mid)
		return;
	if(i>n){
		ans=max(ans,cnt);
		return ;
	}
	cnt+=a[i].a;
	x++;
	dfs(i+1);
	x--;y++;
	cnt-=a[i].a;
	cnt+=a[i].b;
	dfs(i+1);
	y--;z++;
	cnt-=a[i].b;
	cnt+=a[i].c;
	dfs(i+1);
	z--;
	cnt-=a[i].c;
	return ;
}
int df(int i){
	if(i==0)
		return 0;
	if(dp[i])
		return dp[i];
	if(a[i].a>a[i].b&&x<mid){
		x++;
		dp[i-1]=df(i-1);
		return a[i].a+dp[i-1];
	}
	if(a[i].a<=a[i].b&&y<mid){
		y++;dp[i-1]=df(i-1);
		return a[i].b+dp[i-1];
	}
	if(a[i].a>a[i].b&&b[a1+1]<a[i].b){
		dp[i-1]=df(i-1);
		return a[i].a-b[++a1]+dp[i];
	}
	if(a[i].a<=a[i].b&&c[a2+1]<a[i].a){
		dp[i-1]=df(i-1);
		return a[i].b-c[++a2]+dp[i];
	}
	if(a[i].a>a[i].b){
		dp[i-1]=df(i-1);
		y++;
		return a[i].b+dp[i];
	}
	if(a[i].a<=a[i].b){
		x++;dp[i-1]=df(i-1);
		return a[i].a+dp[i-1];
	}
} 
bool cmp(node x1,node x2){
	return x1.a>x2.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		cin>>n;
		if(n<=30){
			ans=0;cnt=0;x=0;y=0;z=0;mid=n/2;
			for(int i=1;i<=n;i++)
				scanf("%d %d %d",&a[i].a,&a[i].b,&a[i].c);
			dfs(1);
			cout<<ans<<"\n";
		}
		if(n>30&&n<=200){
			a1=0;a2=0;
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=n;i++)
				scanf("%d %d %d",&a[i].a,&a[i].b,&a[i].c);
			for(int i=1;i<=n;i++){
				b[i]=a[i].a;c[i]=a[i].b;
			}
			sort(b+1,b+n+1);
			sort(c+1,c+n+1);
			x=0;y=0;mid=n/2;
			cout<<df(n);
		}
		if(n>200){
			bool flag=true;
			for(int i=1;i<=n;i++)
				scanf("%d %d %d",&a[i].a,&a[i].b,&a[i].c);
			for(int i=1;i<=n;i++)
				if(a[i].b!=0)
					flag=false;
			if(flag){
				sort(a+1,a+n+1,cmp);
				for(int i=1;i<=n/2;i++)
					ans+=a[i].a;
				cout<<ans<<"\n";
			}
			else {
				a1=0;a2=0;
				memset(dp,0,sizeof(dp));
				for(int i=1;i<=n;i++){
					b[i]=a[i].a;c[i]=a[i].b;
				}
				sort(b+1,b+n+1);
				sort(c+1,c+n+1);
				x=0;y=0;mid=n/2;
				cout<<df(n);
			}
		}
	}
	return 0;
}
