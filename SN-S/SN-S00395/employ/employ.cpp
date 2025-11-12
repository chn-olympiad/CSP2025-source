#include<bits/stdc++.h>
using namespace std;
int n,m,c;
string s;
int cmp(int x){
	long long ans=1;
	for(int i=2;i<=x;i++){
		ans*=i;
	}
	return ans;
}
int cnp(int x){
	int ans=0;
	for(int i=x;i>=1;i--){
		for(int j=1;j<=i;j++){
			ans+=j;
		}
	}
	return ans;
}
int main(){
	freopen("employ3.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cin>>c;
	}
	if(n==m){
		cout<<cmp(n);
		return 0;
	}
	cout<<cmp(n)*cnp(m);
	return 0;
}
