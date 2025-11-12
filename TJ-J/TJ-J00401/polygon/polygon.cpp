#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[5007];
long long t=1,f=0;
long long y=998244353;
long long dfs(long long x,long long j,long long h){
	if(x>=2){
		if(j==n){
			if(a[j]<h){
				return t;
			}
			return f;
		}
		else{
			if(a[j]<h){
				return (t+dfs(x,j+1,h)+dfs(x+1,j+1,h+a[j]))%y;
			}
			return (dfs(x,j+1,h)+dfs(x+1,j+1,h+a[j]))%y;
		}
	}
	else if(j==n){
		return f;
	}
	return (dfs(x,j+1,h)+dfs(x+1,j+1,h+a[j]))%y;
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(n==3){
		if(max(max(a[1],a[2]),a[3])*2<a[1]+a[2]+a[3]){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		sort(a+1,a+1+n);
		cout<<dfs(0,1,0);
	}
	return 0;
}
