#include<bits/stdc++.h>
using namespace std;
long long  n,m,one,c[501],arr[1001],f[501],used[501],ans;
string s;
void dfs(int ss){
	if(ss==n){
		int ok=0,has_break=0;
		for(int i=1;i<=n;i++){
			if(c[arr[i]]>has_break&&s[i-1]=='1'){
				ok++;
				
			}
			else{
				has_break++;
			}
		}
		if(ok>=m){
			ans++;
			ans%=998224353;
		}
	}
	for(int i=1;i<=n;i++){
		if(used[i]==0){
			used[i]=1;
			arr[ss+1]=i;
			dfs(ss+1);
			arr[ss+1]=0;
			used[i]=0;
		}
	}
}
int main(){
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	cin>>n>>m;
	
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			one++;
		}
		f[i]=f[i-1]+s[i]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m>one){
		cout<<0;
		return 0;
	}
	if(one==n){
		long long sum=1;
		for(int i=1;i<=n;i++){
			sum*=i;
			sum%=998224353;
		}
		cout<<sum;
		return 0;
	}
	dfs(0);
	cout<<ans;
	
}
