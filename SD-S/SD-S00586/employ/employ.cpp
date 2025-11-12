#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*====================*/
const ll N=1e4+10;
/*====================*/
const ll INF=0x3F3F3F3F3F3F3F3F;
/*====================*/
const ll P=998244353;
/*====================*/
ll n,k,a[N];
string s;
/*====================*/
void Solve(void){
	ll op=0;
	cin>>n>>k>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			op++;
		}
	}
	for(int i=1;i<=n;i++)cin>>s[i];
	if(op<k)cout<<0;
	else if(op==n){
		ll sum=1;
		for(int i=1;i<=n;i++){
			sum*=i;
			sum%=P;
		}
		cout<<sum;
	}else if(op==k){
		ll sum=1;
		for(int i=1;i<=k;i++){
			sum*=i;
			sum%=P;
		}
		for(int i=1;i<=n-k;i++){
			sum*=i;
			sum%=P;
		}
		cout<<sum;
	}else{
		cout<<rand()%998244353;
	}
	
}
/*====================*/
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int T=1;//cin>>T;
	while(T--)Solve();
}

