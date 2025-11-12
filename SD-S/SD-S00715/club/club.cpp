#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int T,n,vis[N];
struct P{
	int a1,a2,a3,id;
}num[N];
int maxx=-1;
void dfs(int x,int ca,int cb,int cc,int ans){
	if(x==n+1){
		maxx=max(maxx,ans);
		return ;
	}
	if(ca+1<=n/2)dfs(x+1,ca+1,cb,cc,ans+num[x].a1);
	if(cb+1<=n/2)dfs(x+1,ca,cb+1,cc,ans+num[x].a2);
	if(cc+1<=n/2)dfs(x+1,ca,cb,cc+1,ans+num[x].a3);	
}
bool cmpA(P a,P b){
	if(a.a1!=b.a1)return a.a1>b.a1;
	return a.a2>b.a2;
}
struct nodeA{
	int a1,a2,a3;
	bool operator<(const nodeA &x)const{
		return x.a1<a1;
	}
};
struct nodeB{
	int a1,a2,a3;
	bool operator<(const nodeB &x)const{
		return x.a2<a2;
	}
};
priority_queue<nodeA>qa;
priority_queue<nodeB>qb;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		int A=1,B=1;
		for(int i=1;i<=n;i++){
			cin>>num[i].a1>>num[i].a2>>num[i].a3;
			num[i].id=i;
			if(num[i].a2!=0||num[i].a3!=0)A=0;
			if(num[i].a3!=0)B=0;
		}
		if(A){
			int ans=0;
			sort(num+1,num+1+n,cmpA);
			for(int i=1;i<=n/2;i++){
				ans+=num[i].a1;
			}
			cout<<ans<<"\n";
			continue;
		}
		if(B){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(num[i].a1>num[i].a2){
					if(qa.size()+1<=n/2)qa.push({num[i].a1,num[i].a2,num[i].a3});
					else {
						nodeA t=qa.top();
						int f=num[i].a1-t.a1-num[i].a2+t.a2;
						if(f>0){
							qa.pop();
							qa.push({num[i].a1,num[i].a2,num[i].a3});
							qb.push({t.a1,t.a2,t.a3});
						}
						else{
							qb.push({num[i].a1,num[i].a2,num[i].a3});	
						}
					}
				}
				else if(num[i].a1<num[i].a2){
					if(qb.size()+1<=n/2)qb.push({num[i].a1,num[i].a2,num[i].a3});
					else {
						nodeB t=qb.top();
						int f=num[i].a2-t.a2-num[i].a1+t.a1;
						if(f>0){
							qb.pop();
							qb.push({num[i].a1,num[i].a2,num[i].a3});
							qa.push({t.a1,t.a2,t.a3});
						}
						else{
							qa.push({num[i].a1,num[i].a2,num[i].a3});
						}
					}
				}
				else if(num[i].a1==num[i].a2){
					if(qb.size()+1<=n/2)qb.push({num[i].a1,num[i].a2,num[i].a3});
					else qa.push({num[i].a1,num[i].a2,num[i].a3});
				}
			}
			while(!qa.empty()){
				ans+=qa.top().a1;
				qa.pop();
			}
			while(!qb.empty()){
				ans+=qb.top().a2;
				qb.pop();
			}
			cout<<ans<<"\n";
			continue;
		}
//		for(int i=1;i<=n;i++){
//			if(cnt)
//			dp[i][1]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+num[i].a1;
//			dp[i][2]=max(dp[i-1][2],max(dp[i-1][1],dp[i-1][3]))+num[i].a2;
//			dp[i][3]=max(dp[i-1][3],max(dp[i-1][1],dp[i-1][2]))+num[i].a3;
//		}
//		cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<"\n";
	    maxx=-1;
	    dfs(1,0,0,0,0);
	    cout<<maxx<<"\n";
	}
	return 0;
}
