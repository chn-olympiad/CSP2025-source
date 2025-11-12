#include<bits/stdc++.h>//32pts
#define int long long
#define mod 998244353
using namespace std;
long long n,m,c[505],s[505];
namespace Subtask1{//8pts
	int p[505],ans=0,sum=0,ps=0;
	signed main(){
		for(int i=1;i<=n;i++){
			p[i]=i;
		}
		do{
			sum=0,ps=0;
			for(int i=1;i<=n;i++){
				if(s[i]==0||sum>=c[p[i]]){
					sum++;
				}
				else{
					ps++;
				}
			}
			if(ps>=m){
				ans++;
				ans%=mod;
			}
		}while(next_permutation(p+1,p+1+n));
		cout<<ans<<endl;
		return 0;
	}
};
namespace Subtask2{//20pts
	inline bool check(){
		for(int i=1;i<=n;i++){
			if(s[i]==0){
				return 0;
			}
		}
		return 1;
	}
	inline int fac(int x){
		int fact=1;
		for(int i=1;i<=n;i++){
			fact*=i;
			fact%=mod;
		}
		return fact;
	}
	signed main(){
		cout<<fac(n)<<endl;
		return 0;
	}
};
namespace Subtask3{
	
};
namespace Subtask4{//4pts
	signed main(){
		for(int i=1;i<=n;i++){
			if(s[i]==0){
				cout<<0<<endl;
				return 0;
			}
		}
		return 0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		if(ch=='0'){
			s[i]=0;
		}
		else{
			s[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=10){
		Subtask1::main();
		return 0;
	}
	if(Subtask2::check()){
		Subtask2::main();
		return 0;
	}
	if(n==m){
		Subtask4::main();
		return 0;
	}
	return 0;
}
