#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p=171;
const int M=100007
int ha(string s){
	int ans=1;
	for(int i=0;i<s.size();i++){
		ans*=p;
		ans+=s[i];
	}
	return ans;
}
int n,q;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		
	}
	return 0;
}
