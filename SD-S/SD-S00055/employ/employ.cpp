#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505;
const int p=998244353;
int n,m,c[N],pre[N],cnt;
ll ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		pre[i]=pre[i-1];
		if(s[i-1]=='0'){
			f=0;
			pre[i]++;
		} 
		if(!c[i]) cnt++;
	}
	if(f){
		ans=1;
		for(int i=n;i>=1;i--){
			ans*=i;
			ans%=p;
		}
		cout<<ans;
		return 0;
	}
	if(n-pre[n]<m){
		cout<<0;
		return 0;
	}
	return 0;
}

