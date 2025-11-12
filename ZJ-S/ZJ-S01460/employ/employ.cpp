#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=5e3+5;
int n,m;
string s;
bool flag=1;
int c[N];
int f[1<<20][20];
signed main(){
//	system("fc replace.out replace3.ans");
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			flag=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=18){
		int ans=0;
		f[0][0]=1;
		for(int i=1;i<(1<<n);i++){
			int pcnt=0;
			for(int j=1;j<=n;j++){
				if(i&(1<<(j-1))){
					pcnt++;
				}
			}
			for(int j=1;j<=n;j++){
				if(i&(1<<(j-1))){
					for(int k=0;k<=n;k++){
						if(c[j]>=pcnt-k&&s[pcnt]=='1'){
							f[i][k+1]+=f[(1<<j-1)^i][k];
							f[i][k+1]%=mod;
						}
						else{
							f[i][k]+=f[(1<<j-1)^i][k];
							f[i][k+1]%=mod;
						}
					}
					
				}
			}
		}
		for(int i=m;i<=n;i++){
			ans+=f[(1<<n)-1][i];
			ans%=mod;
		}
		cout<<ans<<'\n';
		return 0;
	}
	if(m==n&&!flag){
		cout<<0;
		return 0;
	}
	else{
		int ans=1;
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				cout<<0;
				return 0;
			}
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
