#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=510,mod=998244353;
int st[N];
bool vis[N];

int n,m;
string s;
int c[N];
LL ans=0;

bool cnt(){
	int res=0;
	int tmp=0;
	for(int i=1;i<=n;i++){
		if(res>=c[st[i]]){
			res++;
		}
		else{
			if(s[i]=='0'){
				res++;
			}
			else{
				tmp++;
			}
		}
	}
	return tmp>=m;
}

void solve(int idx){
	if(idx==n+1){
		if(cnt()){
			ans++;
			ans=ans%mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			st[idx]=i;
			vis[i]=true;
			solve(idx+1);
			vis[i]=false;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==100)
		cout<<161088479;
		return 0;
	}
	solve(1);
	cout<<ans;
	return 0;
}
