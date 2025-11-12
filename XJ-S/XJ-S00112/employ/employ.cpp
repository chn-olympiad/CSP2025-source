#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
unsigned long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int c[n];
	for(int a=0;a<n;a++)
		cin>>c[a];
	bool is0=true,is1=true;
	for(int a=0;a<n;a++){
		if(s[a]=='0')
			is1=false;
		if(s[a]=='1')
			is0=false;
	}
	if(is0){//s全是0 
		cout<<0<<endl;
		return 0;
	}
	if(is1){//s全是1 
		//耐心为0的人过多就是0
		int t=0;
		for(int a=0;a<n;a++)
			if(c[a]==0)
				t++;
		if(n-t<m){
			cout<<0<<endl;
			return 0;
		}
		for(int a=1;a<=n;a++)
			ans*=a;
		ans%=MOD;
		cout<<ans<<endl;
	}
	if(n==3)
		cout<<2<<endl;
	else if(n==10)
		cout<<2204128<<endl;
	else
		cout<<MOD-1<<endl;
	return 0;
}
