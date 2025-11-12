#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,m;
char a[510];
int b[510];
int ans;
bool f[510];
void dfs(int step,int sum,int cnt){
	if(step>n){
//		cout<<sum<<' '<<cnt<<endl;
		if(cnt>=m)ans++;
		ans%=mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			if(a[step]=='0'||sum>=b[i])dfs(step+1,sum+1,cnt);
			else dfs(step+1,sum,cnt+1);
			f[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!='1')f=0;
	}
	for(int i=1;i<=n;i++)cin>>b[i];
	if(f){
		int cnt=0;
		for(int i=1;i<=n;i++)if(b[i])cnt++;
		int ans=1;
		for(int i=1;i<=cnt;i++)ans=(ans*i)%mod;
		cout<<ans;
		return 0;
	}
	if(m==1){
		int id=-1;
		for(int i=1;i<=n;i++){
			if(a[i]=='1'){
				id=i;
				break;
			}
		}
		if(id==-1){
			cout<<0;
			return 0;
		}else{
			int t=id-1;
			int cnt,cnt2;
			cnt=cnt2=0;
			for(int i=1;i<=n;i++){
				if(b[i]>t)cnt++;
				else cnt2++;
			}
			int ans=cnt%mod;
			int num=cnt+cnt2-1;
			for(int i=1;i<=num;i++)ans=(ans*i)%mod;
			cout<<ans;
			return 0;
		}
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}