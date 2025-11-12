#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int MAXN=505;
#define int long long
int n,m,ans;
int a[MAXN],b[MAXN];
char s[MAXN];
bool check(){
	int cnt=0,k=0;
	for(int i=1;i<=n;i++){
		if(cnt>=a[b[i]]){
			cnt++;
			continue;
		}else{
			if(s[i]=='1') k++;
			else cnt++; 
		}
	}
	if(k>=m) return 1;
	return 0;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s+1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=i;
	}
	do{
		ans=(ans+check())%mod;
	}while(next_permutation(b+1,b+n+1));
	cout<<ans<<'\n';
	return 0;
}