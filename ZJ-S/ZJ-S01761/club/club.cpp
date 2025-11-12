#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6+10;
int t,n,ans,cnt1,cnt2,cnt3;
struct node{
	int a,b,c;
}d[N];
bool cmp1(node u,node v){
	return u.a>v.a;
}
bool cmp2(node u,node v){
	return u.b>v.b;
}
bool cmp3(node u,node v){
	return u.c>v.c;
}
bool cmp4(node u,node v){
	return (u.a-u.b)>(v.a-v.b);
}
bool cmp5(node u,node v){
	return (u.a-u.c)>(v.a-v.c);
}
bool cmp6(node u,node v){
	return (u.b-u.c)>(v.b-v.c);
}
void dfs(int x,int num1,int num2,int num3,int sum){
	if(x==n+1){
		ans=max(sum,ans);
		return ;
	} 
	if(num1+1<=n/2) dfs(x+1,num1+1,num2,num3,sum+d[x].a);
	if(num2+1<=n/2) dfs(x+1,num1,num2+1,num3,sum+d[x].b);
	if(num3+1<=n/2) dfs(x+1,num1,num2,num3+1,sum+d[x].c);
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=cnt1=cnt2=cnt3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>d[i].a>>d[i].b>>d[i].c;
			cnt1=max(cnt1,d[i].a);
			cnt2=max(cnt2,d[i].b);
			cnt3=max(cnt3,d[i].c);
		} 
		if(cnt2==0 && cnt3==0){
			sort(d+1,d+n+1,cmp1);
			for(int i=1;i<=n/2;i++) ans+=d[i].a;
			cout<<ans<<"\n";
		}
		else if(cnt1==0 && cnt3==0){
			sort(d+1,d+n+1,cmp2);
			for(int i=1;i<=n/2;i++) ans+=d[i].b;
			cout<<ans<<"\n";
		}
		else if(cnt1==0 && cnt2==0){
			sort(d+1,d+n+1,cmp3);
			for(int i=1;i<=n/2;i++) ans+=d[i].c;
			cout<<ans<<"\n";
		}
		else if(cnt3==0){
			sort(d+1,d+n+1,cmp4);
			for(int i=1;i<=n/2;i++) ans+=d[i].a;
			for(int i=n/2+1;i<=n;i++) ans+=d[i].b;
			cout<<ans<<"\n";
		}
		else if(cnt2==0){
			sort(d+1,d+n+1,cmp5);
			for(int i=1;i<=n/2;i++) ans+=d[i].a;
			for(int i=n/2+1;i<=n;i++) ans+=d[i].c;
			cout<<ans<<"\n";
		}
		else if(cnt1==0){
			sort(d+1,d+n+1,cmp6);
			for(int i=1;i<=n/2;i++) ans+=d[i].b;
			for(int i=n/2+1;i<=n;i++) ans+=d[i].c;
			cout<<ans<<"\n";
		}
		else{
			dfs(1,0,0,0,0);
			cout<<ans<<"\n";
		}
	}
	return 0;
}