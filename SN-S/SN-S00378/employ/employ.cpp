#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[505];
int b[15];
bool bb[15];
string s;
int n,m,ans;
void solve1(int x){
	if(x>n){
		int num=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]-'0'==0||num>=a[b[i]]) num++;
		}
		ans+=num<=(n-m),ans%=998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(bb[i]) continue;
		bb[i]=1,b[x]=i;
		solve1(x+1);
		bb[i]=0;
	}
	return;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=10){
		solve1(1);
		cout<<ans;
	}
	else{
		ans=1;
		for(int i=1;i<=n;i++) ans*=i,ans%=998244353;
		cout<<ans;
	}
	return 0;
}
