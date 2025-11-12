#include<iostream>
#include<cstring>
using namespace std;
const int N=5001;
const long long mod=998244313;
int mp[N];
int count(int t){
	int cnt=0;
	while(t>0){
		t=t&(t-1);
		cnt++;
	}
	return cnt;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>mp[i];
	if(n<=30){
		long long ans=0;
		for(int i=1;i<(1<<n);i++){
			if(count(i)<3)continue;
			int mx=0;
			int len=0;
			for(int j=0;j<n;j++){
				if(i&(1<<j)){
					mx=max(mx,mp[j+1]);
					len+=mp[j+1];
				}
			}
			if(mx<<1<len)ans++;
			ans%=mod;
		}
		cout<<ans<<endl;
	}else{
		;
	}
	return 0;
}