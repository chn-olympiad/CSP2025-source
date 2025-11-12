#include<bits/stdc++.h>
#define ll long long
const ll mod= 998244353;
using namespace std;
int n,m,a[510];
bool used[510];
ll ans,cnt1;
string s;
ll A(int x,int y){
	int res=1;
	for(int i=y;i>=y-x+1;i--) res*=i,res%=mod;
	return res;
}
void dfs(int x,int num,int cnt){
	if(num>=m){
		int tx=x-1;
		ans+=A(n-tx,n-tx);
		ans%=mod;
		return ;
	}
	if(x>n) return ;
	for(int i=1;i<=n;i++){
		if(used[i]) continue;
		used[i]=1;
		int tnum=num,tcnt=cnt;
		if(cnt>=a[i]||s[x-1]=='0') tcnt++;
		else tnum++;
		dfs(x+1,tnum,tcnt);
		used[i]=0;
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cnt1=n;
	cin>>s;
	bool flag=1;
	for(int i=0;i<s.size();i++) if(s[i]=='0') flag=0,cnt1--;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0) flag=0;
	}	
	if(m==n){
		if(!flag) cout<<0;
		else cout<<A(n,n);
		return 0;
	}
	if(flag&&m>=21){
		cout<<A(n,n);
		return 0;
	}
	if(m>cnt1){
		cout<<0;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
