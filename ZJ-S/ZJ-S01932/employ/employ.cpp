#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
char s[510];
int c[510],n,m;
int cnt[510],f[510];
int ret[510];
int b[510];
long long ans=0;
void dfs(int l,int r){
	if(l==r+1){
		long long x=0; 
		for(int i=1;i<=r;i++) x+=f[l];
		if(x<m) return;
		long long sum=1;
		int S=0;
		memset(b,0,sizeof(b));
		for(int i=1;i<=r;i++){
			if(f[i]==0){
				S++;	
			}else{
				b[i]=cnt[ret[i]+S+1];
			}	
		}
		S=0;
		for(int i=r;i>=1;i--){
			if(b[i]!=0){
				sum*=(b[i]-S);
				sum%=mod;
				S++;
			}
		}
		for(int i=r;i>=1;i--){
			if(b[i]==0){
				sum*=(n-S);
				sum%=mod;
				S++;
			}
		}
		for(int i=n-r;i>=1;i--){
			sum*=(n-S);
			sum%=mod;
			S++;
		}
		if(sum>0) ans+=sum;
		return;
	}
	f[l]=0;
	dfs(l+1,r);
	f[l]=1;
	dfs(l+1,r);
} 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	scanf("%s",s+1);
	int SS=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='1') SS++;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	if(SS<m){
		cout<<0;
		return 0;
	}
	if(SS==n){
		long long Ans=1;
		for(int i=1;i<=n;i++){
			Ans*=i;
			Ans%=mod;
		}
		cout<<Ans;
		return 0;
	}
	sort(c+1,c+n+1);
	cnt[0]=n;
	int pos=1;
	for(int i=1;i<=n;i++){
		cnt[i]=cnt[i-1];
		while(c[pos]<i&&pos<=n){
			cnt[i]--;
			pos++;
		}
	}
	for(int i=1;i<=n;i++){
		ret[i]=ret[i-1]+((s[i]-'0')^1);
	}
	if(SS<=18){
		dfs(1,SS);
		cout<<ans%mod;
		return 0;
	}
	cout<<0;
	return 0;
} 
