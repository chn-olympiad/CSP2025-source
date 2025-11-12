#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[1000005];
bool f;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	f=0;
	for(int i=0;i<s.size();i++)
		if(s[i]!='1') f=1;
	if(f==0){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%998244353;
		}
		cout<<ans;
		return 0;
	}
}

