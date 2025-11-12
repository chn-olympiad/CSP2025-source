#include<bits/stdc++.h>
using namespace std;
int a[5005];
long long f(int n, int m){
	int ans1=1, ans2=1;
	for(int i=1;i<=n;i++){
		ans1*=i;
	}
	for(int i=1;i<=m;i++){
		ans2*=i;
	}
	for(int i=1;i<n-m;i++){
		ans2*=i;
	}
	ans1/=ans2;
	return ans1;
}
int cnt=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cnt++;
		}
	}
	if(cnt<=2){
		cout<<0<<'\n';
		return 0;
	}
	long long q=0;
	for(int i=3;i<=cnt;i++){
		q+=f(cnt, i)%998244353;
	}
	q%=998244353;
	cout<<q<<'\n';
	return 0;
}
//我想就这样牵着你的手不放开 爱可不可以永远单纯没有伤害 
