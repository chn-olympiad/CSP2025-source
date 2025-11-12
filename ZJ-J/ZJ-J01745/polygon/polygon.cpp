#include<bits/stdc++.h>
using namespace std;
int n,l[5110];
long long cnt;
const int mod=998244353;
long long C(int a,int b){
	int sum=1,um=1,m=1;
	for(int i=1;i<=b;i++){
		sum*=i;
		sum%=mod;
	}
	for(int i=1;i<=a;i++){
		um*=i;
		um%=mod;
	}
	for(int i=1;i<=b-a;i++){
		m*=i;
		m%=mod;
	}
	return (sum/um/m)%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>l[i];
	for(int i=3;i<=n;i++){
		cnt+=C(n,3);
		cnt%=mod;
	}
	cout<<cnt<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
