#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,a[N],c[N],ans;
bool s[N],flag=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		char tmp;
		cin>>tmp;
		s[i]=tmp-'0';
		flag=flag&&s[i];
	}
	for(int i=1;i<=n;++i){
		cin>>c[i];
		flag=flag&&c[i];
	}
	if(n<=10){
		for(int i=1;i<=n;++i)
			a[i]=i;
		do{
			int out=0,res=0;
			for(int i=1;i<=n;++i)
				if(out>=c[a[i]]||!s[i])
					++out;
				else
					++res;
			if(res>=m)	(++ans)%=mod;
//			if(res>=m){
//				cout<<res<<':';
//				for(int i=1;i<=n;++i)
//					cout<<a[i]<<"\n "[i<n];
//			}
		}while(next_permutation(a+1,a+1+n));
	}
	else if(flag){
		ans=1;
		for(int i=2;i<=n;++i)
			ans=1ll*ans*i%mod;
	}
	cout<<ans;
	return 0;
}