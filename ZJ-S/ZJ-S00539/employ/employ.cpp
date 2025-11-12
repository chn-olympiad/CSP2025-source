#include<bits/stdc++.h>
using namespace std;
#define int long long
const int cd=505,mod=998244353;
int n,m,c[cd],cntt,flag;
string s;
signed main(){
	freopen("employ4.in","r",stdin);
//	freopen("employ.out","w",stdout);
	
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(cntt>=c[i]) cntt++;
		if(c[i]>=s.size()) flag=1;
	}
	int cnt1=0,cnt=n-cntt;
	for(auto i:s){
		cnt1+=(i=='1');
	}
	if(cnt1==s.size()){
		cout<<n<<"\n";
		int sum=1;
		for(int i=1;i<=cnt;i++){
			sum=sum%mod*i%mod;
		}
		cout<<sum;
	}
	if(m==1){
		for(int i=0;i<s.size();i++){
			if(s[i]=='1'){
				int sum=1;
				for(int i=1;i<=cnt;i++){
					sum=sum%mod*i%mod;
				}
				cout<<sum;
				break;
			}
		}
		
	}
	return 0;
}
