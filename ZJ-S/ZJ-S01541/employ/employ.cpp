#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,mod=998244353;
int n,m,l;
string s;
int sol(int x){
	int sum=1;
	for(int i=1;i<=x;i++){
		sum*=i;
		sum%=mod; 
	}
	return sum;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;l=s.size();
	bool flag=1;
	for(int i=0;i<n;i++){
		if(s[i]!='1'){
			flag=0;
			break;
		}
	}
	if(flag){
		cout<<sol(n);
	}
	return 0;
}    
