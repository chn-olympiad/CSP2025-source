#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,ans=1,cnt,sum;
int c[505];
string s;

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<=n-1;i++){
		if(s[i]=='0'){
			cnt++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++){
		if(c[i]<=c[cnt])sum++;
		else break;
	}
//	cout<<sum<<" "<<cnt<<endl;
	for(int i=1;i<=sum;i++){
		ans*=i;
		ans%=mod;
	}
	for(int i=1;i<=(n-sum);i++){
		ans*=i;ans%=mod;
	}
	cout<<ans;
}