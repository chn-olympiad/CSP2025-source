#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
int n,m,c[510];
ll ans;
bool flag=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=0;i<n;i++){
		if(!s[i]){
			flag=0;
			break;
		}
	}
	if(flag){
		ans=1;
		for(int i=2;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}