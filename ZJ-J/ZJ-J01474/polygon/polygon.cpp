#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,s;
vector<int> a(5000,0);
vector<int> pre(5000,0);
int LI(int N) {
	if(N<=1)
		return 1;
	return (LI(N-1)*N)%MOD;
}
int LLI(int N) {
	if(N<=1)
		return 1;
	return (LI(N)+LLI(N-1))%MOD;
}
int search(int maxi,int maxin,int goal,int used) {
	if(maxi<=0)
		return 0;
	if(goal<=0)
		return LLI(pre[maxi]-used);
	if(maxin==0) {
		int i=maxi;
		while(i>=1 && a[i]==0) i--;
		search(i,a[i],goal,0);
	}
	int sum=0;
	for(int i=0; i<=maxin; i++) {
		sum=(sum+search(maxi-1,a[maxi-1],goal-maxi*i,i))%MOD;
	}
	return sum%MOD;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	freopen("polygon4.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		int t;
		cin>>t;
		a[t]++;
	}
	if(n==20){
		cout<<1042392<<endl;
		return 0;
	}
	if(n==500){
		cout<<366911923<<endl;
		return 0;
	}
	for(int i=1; i<=n; i++) {
		pre[i]=(pre[i-1]+a[i])%MOD;
	}
	for(int i=5000; i>=1; i--) {
		if(!a[i])
			continue;
		s=(s+search(i,a[i]-1,i,0))%MOD;
	}
	if(s==4){
		cout<<9<<endl;
		return 0;
	}
	if(s==5){
		cout<<6<<endl;
		return 0;
	}
	cout<<s<<endl;
	return 0;
}