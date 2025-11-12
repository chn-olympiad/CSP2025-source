#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505],v[505];
long long ans;
string s;
vector<int> z;
void dfs(int t){
	if(t==n+1){
		int f=0,l=0;
		for(int i=0;i<n;i++){
			if(f>=z[i]||s[i]=='0') f++;
			else if(s[i]=='1') l++;
			if(l>=m){
				ans++;
				ans%=mod;
				return;
			}
			if(f>n-m) return;
		}
	}
	for(int i=0;i<n;i++){
		if(!v[i]){
			int h=c[i];
			z.push_back(h);
			v[i]=1;
			dfs(t+1);
			v[i]=0;
			z.pop_back();
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	bool tsa=1;
	scanf("%d%d",&n,&m);
	cin >> s;
	for(int i=0;i<n;i++){
		scanf("%d",&c[i]);
		if(c[i]!=1) tsa=0;
	}
	if(tsa){
		ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%mod;
		int k=s.size();
		for(int i=0;i<s.size();i++) if(s[i]=='0'){
			k=i;
			break;
		}
		printf("%lld",ans*k%mod);
		return 0;
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}

