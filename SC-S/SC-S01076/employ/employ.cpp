#include<bits/stdc++.h>
using namespace std;

int n,m,d;
bool bo[510];
char c[510];
long long mod=998244353;
long long ans=1;
long long ca[510];
int x[510];
void dfs(int d,int p){
	
	if(d>n){
		return;
	}
	for(int i=1;i<=n;i++){
		if(bo[i]==0){
			if(x[i]<=p||c[d]=='0'){
				bo[i]=1;
				if(n-m==p){
					ans-=ca[n-d];
					ans%=mod;
					ans+=mod;
					ans%=mod;
				}
				dfs(d+1,p+1);
				bo[i]=0;
			}else{
				bo[i]=1;
				dfs(d+1,p);
				bo[i]=0;
			}
		}else{
			
		}
	}
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	ca[0]=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		(ca[i]=ca[i-1]*i)%=mod;
		if(c[i]=='1'){
			d++;
		}
	}
	ans=ca[n];
	
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	dfs(1,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 