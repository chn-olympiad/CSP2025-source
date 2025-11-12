#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c[505],w[505]={0},cnt=0;
	string s;
	cin>>n>>m>>s;
	int t=n;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1') cnt++;
	}
	int o=0;
	for(int i=0;i<=n;i++){
		int x;
		cin>>x;
		if(x==0) o++;
	}
	if(cnt==n){
		if(n-o<m){
			cout<<0;
			return 0;
		}
		int fac=1;
		while(t){
			fac=(fac*t)%N;
			t--;
		}
		cout<<fac;
		return 0;
	}
	else if(n==m){
		cout<<0;
		return 0;
	}
	if(m>min(cnt,n-o)){
		cout<<0;
		return 0;
	}
}
