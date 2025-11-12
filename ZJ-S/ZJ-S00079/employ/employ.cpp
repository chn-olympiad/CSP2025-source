#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int t[501],c[501],sum=0,tt[501];
int f(int m,int n){
	long long ans=1;
	for(int i=n;i>=n-m+1;i--){
		ans*=i;
		for(int i=m;i>=2;i--){
			if(ans%i==0&&tt[i]==0){
				ans/=i;
				tt[i]++;
				cout<<ans;
			}
		}
	}
	return ans%N;
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(t[c[i]]==0){
			t[c[i]]++;
			sum++;
		}
	}
	cout<<f(m,sum);
	return 0;
}
