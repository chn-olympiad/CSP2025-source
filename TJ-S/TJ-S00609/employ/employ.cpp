#include <bits/stdc++.h>
using namespace std;
long long ans,n,m,s,c,b[1010],k=0;
string st;
bool f;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>st;
	f=false;
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++){
		cin>>c;
		if(c==0)f=true;
		if(c==0)k++;
		b[c]++;
	}
	for(int i=0;i<st.size();i++){
		if(st[i]=='0')f=true;
	}
	if(n==m){
		if(f){
			cout<<0;
			return 0;
		}else{
			ans=1;
			for(int i=1;i<=500;i++){
				if(b[i]!=0){
					ans=ans*b[i]%998244353;
				}
			}
			cout<<ans<<endl;
			return 0;
		}
	}
	else if(m==1){
		ans=(n-k)%998244353;
		for(int i=1;i<=n-1;i++){
			ans=ans*i%998244353;
		}
	}
	ans%=998244353;
	cout<<ans<<endl;
	return 0;
}
