#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5,MOD = 998244353;
int n,m;
int sum=1;
string s,s1="";
int c[N];
int main(){
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int k=n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) k--;
		s1+="1";
	}
	if(k<m){
		cout<<0<<'\n';
		return 0;
	} 
	if(s1==s){
		for(int i=1;i<=n;i++){
			sum*=i;
			sum%=MOD;
		}
		cout<<sum;
	}
	return 0;
}

