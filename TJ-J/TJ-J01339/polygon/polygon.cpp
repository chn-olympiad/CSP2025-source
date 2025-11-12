#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define cin in
#define cout out
#define endl '\n'
ll n,a[5005]={},sum=0,ma=0;
ll dfs(int i){
	if(i==n){
		return (sum>ma*2?1:0);
	}
	ll s=0,m=ma;
	sum+=a[i];
	ma=max(ma,a[i]);
	s+=dfs(i+1);
	sum-=a[i];
	ma=m;
	s+=dfs(i+1);
	return s%998244353;
}
int main(){
	fstream in,out;
	in.open("polygon.in",ios::in);
	out.open("polygon.out",ios::out);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	cout << dfs(0) << endl;
	return 0;
}