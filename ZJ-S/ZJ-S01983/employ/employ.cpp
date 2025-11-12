#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
string s;
long long num,n,m;
long long A(long long x,long long y){
	int ans=1;
	for(int i=y;i>=y-x+1;i--){
		ans*=i;
		ans%=mod;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++){
		num+=((s[i]=='1')?1:0);
	}
	int x,j=0;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x==0){
			j++;
		}
	}
	if(num==s.size()){
		cout<<A(n-j,n-j);
		return 0;
	}
	if(num<m){
		cout<<0;
		return 0;
	}
}
