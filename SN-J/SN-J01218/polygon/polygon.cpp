/*SN-J01218 龙瑀泽 西安市曲江第一中学*/
#include<bits/stdc++.h>
using namespace std; 
int a[5090];
int fxxk(int mx,int f){
	if(x==2)
}
int main(){
	int n;
	cin>>n;
	int jl=n;
	for(int i=2;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long e=0;
	while(jl>=3){
		long long mx=a[jl];
		for(int i=1;i<jl-1;i++){
			if(a[i]+a[jl-1]>mx){
				if(jl-3>=1){
					long long jb=fxxk(jl-2);
					e=(e+jb)%998244353;
					e=(e-i+1)%998244353;
					e+=i;
					break;
				}
				else{
					e=(e+1)%998244353;
				}
				break;
			}
		}
		jl--;
	}
	cout<<e;
	return 0;
}










