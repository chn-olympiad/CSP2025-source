#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,pation[505],sum,ans,membout,xl[505],xxxqwe=1;
string tests;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>tests;
	for(int i=1;i<=n;i++){
		xxxqwe*=i;
		xl[i]=i;
		if(tests[i-1]=='1')sum++;
		cin>>pation[i];
	}
	if(sum<m||n>12){
		cout<<0;
		return 0;
	}
	ans=0;
	for(int _=0;_<xxxqwe;_++){
		sum=0;
		membout=0;
		for(int i=1;i<=n;i++){
			if(membout>=pation[xl[i]] || tests[i-1]=='0'){
				membout++;
			}else{
				sum++;
			}
		}
		if(sum>=m){
			ans++;
		}
		next_permutation(xl+1,xl+1+n);
	}
	cout<<ans%998244353;
	return 0;
}
//100+80+<25+>8 

