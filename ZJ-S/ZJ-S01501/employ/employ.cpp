#include<bits/stdc++.h>
using namespace std;
const int N=550;
const int Mod=998244353;
int n,m;
string s;
int c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	int s1=0,s0=0;
	for(int i=0;i<s.size();i++){
		if(s[i]==1) s1++;
		if(s[i]==0) s0++;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) i--,n--;
	}
	if(n<m||s1<m){
		cout<<0;
	}
	else if(s0==0){
		long long ans=1;
		int n1=n;
		for(int i=1;i<=m;i++){
			ans=(ans*n1)%Mod;
			n1--;
		}
		cout<<ans;
	}
	return 0;
}
