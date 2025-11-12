#include<iostream>
using namespace std;
const long long inf=998244353;
long long n,m,a[510],flag,ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=0;i<s.size();i++){
		if(s[i]!='1'){
			flag=1;
		}
	}
	if(flag==0){
		ans=1;
		for(int i=2;i<=n;i++) ans*=i,ans=(ans+inf)%inf;
	}
	cout<<ans;
	return 0;
}

