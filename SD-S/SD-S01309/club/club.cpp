#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Node{int a[4];}s[100005];
int T,n,v[4],ans;
vector<int>vecA;
bool flagA;
void dfs(int k,int sum){
	if(k>n){
		ans=max(ans,sum);
		return ;
	} 
	for(int i=1;i<=3;i++)
		if(v[i]<(n>>1)){
			v[i]++;
			dfs(k+1,sum+s[k].a[i]);
			v[i]--;
		}
}
void solveA(){
	sort(vecA.begin(),vecA.end(),greater<int>());
	for(int i=0;i<(n>>1);i++) ans+=vecA[i];
}
void solve(){
	ans=flagA=0LL;
	cin>>n;
	vecA.clear();
	for(int i=1;i<=n;i++){
		cin>>s[i].a[1]>>s[i].a[2]>>s[i].a[3];
		vecA.push_back(s[i].a[1]);
		if(s[i].a[2]!=0LL||s[i].a[3]!=0LL) flagA=1;
	}
	if(!flagA) solveA();
	else if(n<=10) dfs(1,0);
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) solve();
	return 0;
}
