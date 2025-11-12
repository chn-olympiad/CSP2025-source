#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M=998244353;
ll n,m,nx[1145],cnt,vis[1145],ans[1145],an;

string s;
void qpl(ll stp){
	if(stp==n+1){
		ll cnt=0;
		for(ll i=1;i<=n;i++){
			if(cnt>=nx[ans[i]])cnt++;
			else if(s[i-1]=='0')cnt++;
		}
		an+=(n-cnt>=m);
		return;
	}
	for(ll i=1;i<=n;i++){
		if(!vis[i]){
			ans[stp]=i;
			vis[i]=1;
			qpl(stp+1);
			vis[i]=0;
		}
	}
}
void main1(){
	qpl(1);
	cout<<an;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(ll i=1;i<=n;i++){
		cin>>nx[i];
		if(nx[i])cnt++;
		
	}
	if(n<=10){
		main1();
	}
	return 0;
}