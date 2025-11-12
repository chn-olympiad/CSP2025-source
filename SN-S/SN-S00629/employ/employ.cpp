#include<bits/stdc++.h>
using namespace std;
const int N=20;
const int mod=998244353;
int n,m,c[N],ans;
bool z[N];
string s;
bool op[N];
int q[N];
int dp[(1<<N)][N];
void dfs(int id){
	if(id>n){
		int fq=0;
		for(int i=1;i<=n;i++){
//			cout<<q[i]<<" ";
			if(!z[i])++fq;
			else{
				if(fq>=c[q[i]])++fq;
				else continue;
			}
		}
//		cout<<endl;
		if(n-fq>=m)ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(op[i])continue;
		q[id]=i;op[i]=true;
		dfs(id+1);op[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;for(int i=0;i<n;i++)if(s[i]=='0')z[i+1]=false;else z[i+1]=true;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10){
		dfs(1);
		cout<<ans<<endl;
	}
	else{
		dp[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<(1<<n);j++){
				bool op[30]={};int cnt=0;
				for(int k=1;k<=n;k++){
					if(j&(1<<(k-1)))op[k]=true,++cnt;
				}
				if(cnt>i-1)continue;
				for(int k=1;k<=n;k++){
					if(op[k])continue;
					for(int fq=0;fq<=n-m;fq++){
						int d=fq;
						if(!z[i])++d;
						else {
							if(fq>=z[k])++d;
						}
						dp[j|(1<<(k-1))][d]+=dp[j][fq];
						dp[j|(1<<(k-1))][d]%=mod;
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<=n-m;i++){
			ans+=dp[(1<<n)-1][i];
			ans%=mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}
