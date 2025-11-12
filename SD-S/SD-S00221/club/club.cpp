#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,T;
struct Node{
	int t[5],x;
}a[100010];
int ans=0;
void dfs(int s1,int s2,int s3,int cnt1,int cnt2,int cnt3,int x){
	if(x==n+1){ans=max(ans,s1+s2+s3);return;}
	if(cnt1<n/2)dfs(s1+a[x].t[1],s2,s3,cnt1+1,cnt2,cnt3,x+1);
	if(cnt2<n/2)dfs(s1,s2+a[x].t[2],s3,cnt1,cnt2+1,cnt3,x+1);
	if(cnt3<n/2)dfs(s1,s2,s3+a[x].t[3],cnt1,cnt2,cnt3+1,x+1);
}
bool cmp_A(Node a,Node b){
	return a.t[1]>b.t[1];
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		bool spe_A=true;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].t[1]>>a[i].t[2]>>a[i].t[3];
			if(a[i].t[2]>0||a[i].t[3]>0)spe_A=false; 
		}
		if(spe_A==true){
			sort(a+1,a+n+1,cmp_A);
			for(int i=1;i<=n/2;i++)ans+=a[i].t[1];
			cout<<ans<<endl;
		}else{
			dfs(0,0,0,0,0,0,1);
			cout<<ans<<endl;
		}
	}
	return 0;
}
