#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505,mod=998244353;
int n,m;
string s;
int c[N];
int p[N];
int pos[N];
bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++)cnt+=(s[i]=='1');
	return cnt<m;
}
bool check2(){
	int cnt=0;
	for(int i=1;i<=n;i++)cnt+=(s[i]=='1');
	return cnt<=18;
}
int tr[N];
void update(int x){
	for(int i=x;i<=n+1;i+=i&-i)tr[i]++;
}
int ask(int x){
	int ret=0;
	for(int i=x;i;i-=i&-i)ret+=tr[i];
	return ret;
}
int popcount(int x){
	int ret=0;
	while(x){
		ret++;
		x&=(x-1);
	}
	return ret;
}
int jc[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;s=" "+s;
	for(int i=1;i<=n;i++){
		scanf("%d",c+i);
	}
	if(check()){
		cout<<0<<'\n';
		return 0;
	}
	if(n<=10){
		for(int i=1;i<=n;i++)p[i]=i;
		int ans=0;
		do{
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(s[i]=='1'){
					if(c[p[i]]>i-1-cnt)cnt++;
				}
			}
			ans+=(cnt>=m);
		}while(next_permutation(p+1,p+n+1));
		cout<<ans<<'\n';
		return 0;
	}
	if(m==1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1')pos[++cnt]=i-1;
		}
		sort(c+1,c+n+1);
		int j=1;
		int ans=1;
		for(int i=1;i<=cnt;i++){
			while(j<=n&&c[j]<=pos[i])j++;
			j--;
			ans=(ll)ans*(j-i+1)%mod;
		}
		for(int i=1;i<=n-cnt;i++)ans=(ll)ans*i%mod;
		int t=1;
		for(int i=1;i<=n;i++)t=(ll)t*i%mod;
		cout<<(t-ans+mod)%mod<<'\n';
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				cout<<"0\n";
				return 0;
			}
		}
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				cout<<"0\n";
				return 0;
			}
		}
		int t=1;
		for(int i=1;i<=n;i++)t=(ll)t*i%mod;
		cout<<t<<'\n';
		return 0;
	}
	if(check2()){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1')pos[++cnt]=i-1;
		}
		int ans=0;
		jc[0]=1;
		for(int i=1;i<=n;i++)jc[i]=(ll)jc[i-1]*i%mod;
		for(int i=1;i<=n;i++)update(c[i]+1);
		for(int i=0;i<(1<<cnt);i++){
			if(popcount(i)<m)continue;
			int now=1;
			int t=0;
			for(int j=0;j<cnt;j++){
				if((i>>j)&1){
					//c[]>j-t
					now=(ll)now*max(0,n-ask(pos[j+1]-t+1)-t)%mod;
					t++;
				}else{
					//c[]<=j-t
					now=(ll)now*max(0,ask(pos[j+1]-t+1)-(j-t))%mod;
				}
			}
			now=(ll)now*jc[n-cnt]%mod;
			ans=(ans+now)%mod;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
