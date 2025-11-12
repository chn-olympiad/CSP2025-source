//SN-J01073 郭逸凡 西安滨河学校 
#include<bits/stdc++.h>
using namespace std;
int a[5090];
int fun(int x){
	if(x==2)	return 2;
	return (x*fun(x-1))%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int jl=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long cnt=0;
	while(jl>=3){
		long long maxx=a[jl];
		for(int i=1;i<jl-1;i++){
			if(a[i]+a[jl-1]>=maxx){
				if(jl-2>1){
					long long kk=fun(jl-2);
					cnt=(cnt+kk+1)%998244353; 
					cnt=(cnt-i+1)%998244353;
				}
				break;
			}
			
		}
		jl--;	
	}
	cout<<cnt-1;
	return 0;
} 
