#include <bits/stdc++.h>
using namespace std;
int t,n,flb,fla,ans;
struct node{
	int a[5];
}s[100005];
bool cmpa(node x,node y){
	return x.a[1]>y.a[1];
}
void dfs(int st,int b1,int b2,int b3,int cnt){
	if(b1<0||b2<0||b3<0) return;
	if(st==n+1){
		ans=max(ans,cnt);
		return ;
	}
	dfs(st+1,b1-1,b2,b3,cnt+s[st].a[1]);
	dfs(st+1,b1,b2-1,b3,cnt+s[st].a[2]);
	dfs(st+1,b1,b2,b3-1,cnt+s[st].a[3]);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=fla=flb=0;
		for(int i=1;i<=n;i++){
			cin>>s[i].a[1]>>s[i].a[2]>>s[i].a[3];
			if(s[i].a[2]!=0||s[i].a[3]!=0) fla=1;
			if(s[i].a[3]!=0) flb=1;
		}
		if(fla==0){
			sort(s+1,s+1+n,cmpa);
			for(int i=1;i<=n/2;i++) ans+=s[i].a[1];
		}else{
			dfs(0,n/2,n/2,n/2,0);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
