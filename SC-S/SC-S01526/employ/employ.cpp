#include<bits/stdc++.h>
using namespace std;
const int N=566,MOD=998244353;
int n,m;
long long ans;
int c[N],b[N],s[N],a[N],len;
void dfs(int p){
	if(p==n){
		int los=0,sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]<=los){
				los++;
			}else{
				if(s[i]==1){
					sum++;
				}else{
					los++;
				}
			}
		}
		if(sum>=m){
			ans=(ans+1)%MOD;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			len++;
			a[len]=c[i];
			dfs(p+1);
			b[i]=0;
			a[len]=0;
			len--;
		}
	}
}
bool fok;
int cnt;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	string ts;
	cin>>ts;
	for(int i=1;i<=n;i++){
		s[i]=ts[i-1]-'0';
		if(s[i]==0){
			fok=true;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0)cnt++;
	}
	if(!fok){
		ans=1;
		for(int i=2;i<=cnt;i++){
			ans=(ans*i)%MOD;
		}
	}
	else{
		dfs(0);
	} 
	cout<<ans%MOD;
	return 0;
} 