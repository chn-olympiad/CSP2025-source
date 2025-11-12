#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;

int n,m;
string s;
int a[510];
long long ans;
const long long mod=998244353;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		long long sum=1;
		for(int i=1;i<n;i++)sum=sum*i%mod;
		for(int i=1;i<=n;i++){
			int cnt=0;
			int tot=0;
			for(int j=0;j<s.size();j++){
				if(cnt==a[i])break;
				if(s[j]=='0')cnt++;
				else ans = (ans+1)%mod;
			}
		}
		cout<<ans*sum%mod<<endl;
	}
    return 0;
}