#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,ans,cnt,res,c[1011];
string s;
bool check[1011];
void dfs(int depth){
	if(ans>=m&&depth==n+1){
		res++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!check[i]){
			int tempc=cnt,tempa=ans;
			check[i]=1;
			if(s[depth-1]=='0'){
				cnt++;
			}
			else if(cnt>=c[i]){
				cnt++;
			}
			else{
				ans++;
			}
			dfs(depth+1);
			check[i]=0;
			cnt=tempc;
			ans=tempa;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<res%mod<<"\n";
	return 0;
}
