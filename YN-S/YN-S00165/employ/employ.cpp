//I love Nagato Yuki forever!!!
#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace Z3k7223{
	const int N=510,mod=998244353;
	int n,m,a[N],s[N],p[N];
	void main(){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			char ch;
			cin>>ch;
			a[i]=ch-'0';
		}
		for(int i=1;i<=n;i++){
			cin>>s[i];
			p[i]=i;
		}
		if(n>10){
			for(int i=1;i<=n;i++){
				if(a[i]==0||s[i]==0){
					cout<<"0\n";
					return;
				}
			}
			int ans=1;
			for(int i=1;i<=n;i++){
				ans=(ll)ans*i%mod;
			}
			cout<<ans<<'\n';
			return;
		}
		int ans=0;
		do{
			int nowx=0,sum=0;
			for(int i=1;i<=n;i++){
				if(nowx>=s[p[i]]||a[i]==0){
					++nowx;
				}else{
					++sum;
				}
			}
			ans+=(sum>=m);
		}while(next_permutation(p+1,p+1+n));
		cout<<ans<<'\n';
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	Z3k7223::main();
	return 0;
}
