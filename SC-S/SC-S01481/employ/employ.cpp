#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=1e6+5;
const ll Mod=998244353;
ll n,m,a[N],fl=1,ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=0;i<s.size();i++)
		fl=(s[i]=='1')?1:0;
	if(fl){
		ans=1;
		for(int i=1;i<=s.size();i++)
			ans=ans*i%Mod;
		cout<<ans;
		return 0;
	}
	cout<<Mod-n*m*s;
	return 0;
}