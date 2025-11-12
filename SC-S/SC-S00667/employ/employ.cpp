#include<bits/stdc++.h>
using namespace std;
long long N=998244353;
long long s[1000005];
long long c[1000005];
int main (){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	long long cnt=0;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]==0){
			cnt++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(cnt==0){
		cout<<0;
		return 0;
	}else{
		if(m==n){
			cout<<0;
			return 0;
		}
	}
	
	return 0;
}