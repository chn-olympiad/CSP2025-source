#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[5005];
long long ans;
long long qs[5005];
bool b[5005];
long long v[5005];
const long long mod=998244353;
void dfs(long long x,long long s,long long mx,long long sum){
	if(x>n){
		return;
	}
	if(x==n){
		if(s>=3){
			
			if(sum>2*mx){
				ans++;
			}
		}
	}	
	b[x+1]=1;
	dfs(x+1,s+1,max(mx,a[x+1]),sum+a[x+1]);
	b[x+1]=0;
	dfs(x+1,s,mx,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool isA=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			isA=0;
		}
	}
	if(!isA){
		sort(a+1,a+1+n);
		dfs(0,0,0,0);
		cout<<ans;
	}
	else if(isA){
//		for(int i=1;i<=n+3;i++){
//			long long s=1;
//			for(int j=1;j<=i;j++){
//				s=((s%(mod-2))*(j%(mod-2)))%mod;
//			}
//			v[i]=s;
////			cout<<s<<endl;
//		}
		for(int i=3;i<=n;i++){
			if(n==i){
				ans+=1;
			}
			else{
				long long s;
				for(int j=i+1;j<=n;j++){
					s=((s%(mod-2))*(j%(mod-2))/(n-j+1))%mod;
				}
				ans+=s;
			}		
			ans%=mod;
			
		}
		cout<<ans;
	}
	return 0;
}
/*
20
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
(%(mod-2))
*/
