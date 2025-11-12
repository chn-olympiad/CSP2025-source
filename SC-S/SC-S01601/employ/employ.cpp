#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505],d[505];
int ans;
string s;
vector<int> v;
bool f[505]={false};
void dfs(int k,int p,int q){
	if(n-q<m)return;
	if(k==n){
		if(p>=m){
			ans++;
		}return;
	}for(int i=1;i<=n;i++){
		if(f[i]==false){
			f[i]=true;
			dfs(k+1,(c[i]>q&&s[k]=='1')?p+1:p,(c[i]<=q||s[k]=='0')?q+1:q);
			f[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int l=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=0;i<n;i++){
		d[i]=d[i-1]+s[i]-'0';
	}
	if(n>18&&n!=m){
		long long sum=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				sum++;
			}
		}sum = max(sum,1ll*1);
		for(int i=2;i<=n-1;i++){
			sum=(sum*i)%mod;
		}printf("%ld",sum);
		return 0;
	}else if(n<=18){
		dfs(0,0,0);
		cout<<ans;
		return 0;
	}else if(n==m){
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||c[i]==0){
				printf("%d",0);
				return 0;
			}
		}long long sum=1;
		for(int i=1;i<=n;i++){
			sum=(1ll*sum*i)%mod;
		}printf("%d",sum);
	}
	return 0;
}