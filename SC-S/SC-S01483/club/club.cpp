#include<bits/stdc++.h>
using namespace std;
#define int long long
struct A{
	int a,b,c;
}a[100005];
int T,n,ans,fa,fb,fc;
bool cmp(A x,A y){
	return max(x.a,max(x.b,x.c))>max(y.a,max(y.b,y.c));
}
void dfs(int u,int cnt,int a1,int b,int c){
	if(u==n+1){
		ans=max(cnt,ans);
		return ;
	}
	if(a1<n/2){
		dfs(u+1,cnt+a[u].a,a1+1,b,c);
	}
	if(b<n/2){
		dfs(u+1,cnt+a[u].b,a1,b+1,c);
	}
	if(c<n/2){
		dfs(u+1,cnt+a[u].c,a1,b,c+1);
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0,fa=0,fb=0,fc=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b!=0){
				fb=1;
			}
			if(a[i].c!=0){
				fc=1;
			}
		}
		if(fb==0&&fc==0){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a;
			}
			cout<<ans;
			continue;
		}
		if(n<30){
			dfs(0,0,0,0,0);
			cout<<ans<<"\n";
			continue;
		}
		fa=0,fb=0,fc=0;
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].a>a[i].b&&a[i].a>a[i].c&&fa<n/2){
				ans+=a[i].a;
				fa++;
			}else if(a[i].b>a[i].c&&a[i].b>a[i].a&&fb<n/2){
				ans+=a[i].b;
				fb++;
			}else if(a[i].c>a[i].b&&a[i].c>a[i].b&&fc<n/2){
				ans+=a[i].c;
				fc++;
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}