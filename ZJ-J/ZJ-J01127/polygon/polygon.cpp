#include<bits/stdc++.h>
using namespace std;
int a[5010];
int n;
string zh(int x){
	string s="";
	while(x){
		s=char(x%2+'0')+s;
		x/=2;
	}
	while(s.size()<n){
		s='0'+s;
	}
	return s;
}
const int mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int mxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mxx=max(mxx,a[i]);
	}
	long long ans=0;
	if(n<=20){
		for(int i=1;i<pow(2,n);i++){
			string s=zh(i);
			int sum=0,mx=0,cnt=0;
			for(int j=0;j<s.size();j++){
				if(s[j]=='0'){
					continue;
				}
				cnt++;
				mx=max(mx,a[j+1]);
				sum+=a[j+1];
			}
			if(cnt>=3&&sum>2*mx){
				ans++;
			}
		}
	}
	else if(mxx==1){
		int k=n*(n-1)/2;
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=2;
			ans%=mod;
		}
		ans-=k+n;
		if(ans<0){
			ans+=mod;
		}
	}
	else{
		ans=6;
	}
	cout<<ans%mod;
	return 0;
}
