#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505;
const int P=3e5+5;
const int mod=998244353;
int n,m;
string st;
int s[N],c[N];
//int f[P][20];
int vis[N];
int a[N];
ll ans=0;
ll jc[N];
void init(){
	jc[0]=1;
	for(int i=1;i<=500;i++) jc[i]=(jc[i-1]*i)%mod;
}
void dfs(int nw){
	int fq=0,l=0;
/*	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;*/
	for(int i=1;i<=nw;++i){
		if(fq>=c[a[i]]||s[i]==0){
			fq++;
		//	continue;
		}else{
			l++;
		}
	//	cout<<fq<<","<<l<<" "<<" "<<c[a[i]]<<" "<<s[i]<<endl;
	}
//	cout<<endl;
	if(l>=m) {
		ans=(ans+jc[n-nw]);
		ans%=mod;
		return ;	
	}
	if(l+n-nw<m) return ;
	if(nw==n){	
		return ;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			a[nw+1]=i;
			vis[i]=1;
			dfs(nw+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	init();
	scanf("%d%d",&n,&m);
	cin>>st;
	for(int i=0;i<n;i++){
		s[i+1]=st[i]-'0';
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	dfs(0);
	//f[0][0]=1;
	/*for(int i=1;i<(1<<n);++i){
		int x=i;
		int ct=0;
		while(x){
			ct++;
			if(x&1) vis[ct]=1;
			x>>=1;
		}
		for(int j=1;j<=n;++j){
			if(vis[j]==0) continue;
			vis[j]=0;
			int T=0;
			for(int k=1;k<=n;k++){
				T=T+(vis[k]<<(k-1));
			}
			cout<<T<<" "<<i<<" "<<j<<endl;
			vis[j]=1;
		}
	}*/
	printf("%lld\n",ans);
	return 0;
} 
