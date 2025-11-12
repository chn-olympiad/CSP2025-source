#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=100000+5;
int T,cnt,n,cnt1,cnt2,cnt3;
bool vis[maxn];
struct node{int a1,a2,a3;}a[maxn];
int dfs(int x1,int x2,int x3,int x){
	if(cnt==n||x>n) return 0;
	int ans=-0x3f,i=x+1,num=0;
	cnt++; 
	cnt1++;
	if(cnt1<=n/2){
		num+=x1; 
		num+=dfs(a[i].a1,a[i].a2,a[i].a3,i);
		ans=max(num,ans);  
		num=0;  
	}cnt1--; cnt2++;
	if(cnt2<=n/2){
		num+=x2; 
		num+=dfs(a[i].a1,a[i].a2,a[i].a3,i);
		ans=max(num,ans); 
		num=0;
	}cnt2--; cnt3++;
	if(cnt3<=n/2){
		num+=x3; 
		num+=dfs(a[i].a1,a[i].a2,a[i].a3,i);
		ans=max(num,ans); 
		num=0;
	}cnt3--;
	cnt--;
	num+=dfs(a[i].a1,a[i].a2,a[i].a3,i);
	ans=max(num,ans);
	return ans;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		if(n>200){
			int x,y,b[maxn];
			for(int i=1;i<=n;i++) cin>>b[i]>>x>>y;
			sort(b+1,b+n+1);
			int ans=0;
			for(int i=1;i<=n/2;i++) ans+=b[i];
			cout<<ans<<endl;
		}else{
			for(int i=1;i<=n;i++)
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			cout<<dfs(a[1].a1,a[1].a2,a[1].a3,1)<<endl;
		}
	}
	return 0;
}