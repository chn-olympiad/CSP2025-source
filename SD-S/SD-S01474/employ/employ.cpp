#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int N = 505;
char s[N];
int c[N],n,m;
bool ue[N];
vector<int> v;
long long ans = 0;
void dfs(int a){
	if(a==n+1){
		int cnt = 0,dcnt = 0;
		for(int i=0;i<n;i++){
			if(s[i+1]=='0'||c[v[i]]<=dcnt){
				dcnt++;
			}
			else{
				cnt++;
			}
		}
		if(cnt>=m){
			ans++;
			ans%=MOD;
		}
		
		return;
	}
	for(int i=1;i<=n;i++){
		if(ue[i]){
			continue;
		}
		ue[i] = true;
		v.push_back(i);
		dfs(a+1);
		v.pop_back();
		ue[i] = false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool flag = true;
	int cnt2 = 0;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0'){
			cnt2++;
			flag = false;
		}
	}
	int cnt = 0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			cnt++;
		}
	}
	if(m>n-max(cnt,cnt2)){
		cout<<0;
		
		return 0;
	}
	if(flag){
		sort(c+1,c+n+1);
		ans = 1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=MOD;
		}
		cout<<ans;
		
		return 0;
	}
	dfs(1);
	cout<<ans;
	
	return 0;
}
