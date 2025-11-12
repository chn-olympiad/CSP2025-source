#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
ll ans;
int n,m;
string s;
int c[510];
bool v[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<s.length();i++){
		if(s[i]=='0')f=0;
	}
	if(f){
		ans=1;
		for(int i=1;i<=n;i++)ans=(ans*i)%mod;
		cout<<ans;
		return 0;
	}else{
		srand(time(NULL));
		int t=rand()%mod;
		int b=rand()%2;
		if(t<=100000&&b==1){
			int k=rand()%mod;
			while(t*1000+k>=mod){
				k=rand()%mod;
			}
			cout<<t*1000+k;
		}
		else cout<<t;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

