#include<bits/stdc++.h>
#define N 510
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,m,cnt;
int ans;
int c[N],p[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++)if(s[i]=='1')cnt++;
	if(cnt<m){puts("0");return 0;}
	if(cnt==n){
		int t[N];
		ans=1;
		for(int i=n;i>0;i--)t[i]=ans=(1ll*ans*i)%mod;
		ans=(ans+mod-t[n-m])%mod;
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)p[i]=i;
	do{
		int b=0,d=0;bool flag=true;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='1' && d<c[p[i]]){
				b++;
			}else{
				d++;
			}
			if(b>=m){
				(ans+=1)%mod;
				flag=false;
				break;
			}
		}
		if(b>=m and flag)(ans+=1)%mod;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans<<endl;
	return 0;
}