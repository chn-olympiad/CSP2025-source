#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353
int n,m,c[505],b[505],uesd[505],ans;
string s;
void to_do(){
	int cnt=0,p=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0' || p>=c[b[i]]){
			p++;
			continue;
		}
		if(s[i-1]=='1'){
			p=0;
			cnt++;
		}
	}
	if(cnt>=m) ans++;
}
void dg(int c){
	if(c>n){
		to_do();
		return;
	}
	for(b[c]=1;b[c]<=n;b[c]++){
		if(uesd[b[c]]==0){
			uesd[b[c]]=1;
			dg(c+1);
			uesd[b[c]]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dg(1);
	cout<<ans;
	return 0;
}
