#include<bits/stdc++.h>
using namespace std;
long long n,m,p=998244353,ans=1,c,cnt;
string s;
int f;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c;
		if(!c)cnt++;
	}
	f=n;
	for(int i=0;i<s.size();i++)if(s[i]=='0')f--;
	f=min((long long)f,n-cnt);
	if(f<m){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=p;
	}
	cout<<ans;
	return 0;
}
