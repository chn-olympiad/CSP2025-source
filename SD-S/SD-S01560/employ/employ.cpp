#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,a[N],cnt;
bool f=1,f1=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<s.size();++i){
		cin>>s[i];
		if(s[i]=='0'){
			f=0;
			cnt++;
		}
	}
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]<=cnt)f1=0;
	}
	if(f==1 || f1==1){
		long long ans=1;
		for(int i=1;i<=n;++i){
			ans=ans*i%998244353;
		}
		cout<<ans%998244353<<'\n';
	}
	else{
		int k=-1;
		for(int i=0;i<s.size();++i){
			if(s[i]=='1'){
				k=i;
				break;
			}
		}
		for(int i=1;i<=n;++i){
			if(a[i]>k){
				
			}
		}
	}
	return 0;
}

