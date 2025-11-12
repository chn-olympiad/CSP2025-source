#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
int n,m,a[505],sum=0,cnt=0,sp[505]={1,1},c[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=1;i<501;i++){
		sp[i]=(sp[i-1]*i)%mod;
	}
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		a[i]=s[i]-'0';
		sum+=a[i];
		cin>>c[i];
		if(c[i]){
			cnt++;
		}
	}
	if(m==1){
		if(!sum){
			cout<<0<<endl;
			return 0;
		}
	}
	if(m==n){
		if(sum!=n){
			cout<<0<<endl;
			return 0;
		}
		cout<<sp[n]<<endl;
	}
	if(cnt>=m){
		cout<<sp[n]<<endl;
		return 0;
	}
	cout<<0<<endl;
	return 0;
}

