#include<bits/stdc++.h>
using namespace std;
const int N=505,MOD=998244353;
int yq[N],rrd[N];
int zh[N][N];
int t[N],st[N];
int cnt[N];
int b[N],sb[N];
int n,m,cnt0;
int A(int m,int n){
	long long tmp=1;
	if(n>m)return 0;
	for(int i=m;i>=m-n+1;i--){
		tmp=tmp*i%MOD;
	}
	return tmp;
}
int main(){
	freopen("employ4.in","r",stdin);
//	freopen("employ.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	string str;cin>>str;
	yq[0]=1;
	
	for(int i=0;i<n;i++){
		if(str[i]=='0')yq[i+1]=yq[i]+1,cnt0++;
		else yq[i+1]=yq[i];
	}
	for(int i=0;i<n;i++){
		if(str[i]=='0')yq[i+1]=0;
//		cout<<yq[i+1];
	}
//	cout<<endl;
	yq[0]=0;
	int k=1;
	for(int i=1;i<=n;i++){
		if(yq[i]==0)k++;
		if((yq[i]==yq[i-1]||yq[i-1]==0)&&yq[i]!=0)b[k]++;
	}
	cout<<k<<endl;
	for(int i=1;i<=k;i++){
		sb[i]=sb[i-1]+b[i];
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(b[i])cout<<i<<' '<<b[i]<<endl,sum+=b[k];
	}
//	cout<<cnt0;
//	return 0;
	for(int i=1;i<=n;i++){
		cin>>rrd[i];
		t[rrd[i]]++;
	}
	for(int i=1;i<=n;i++){
		st[i]=st[i-1]+t[i];
	}
//	cout<<k<<endl;
	st[n+1]=0;
//	int tm=m;
//	for(;m<=sb[k];m++){
//		dfs(k,1,0);
//	}
//	cout<<ans;
	if(m==1){
		long long ans=A(n,n),tmp=1,sum=0;
		for(int i=1;i<=k;i++){
			if(b[i]){
				tmp*=A(st[k-1]-sum,b[i]);
				tmp%=MOD;
				sum+=b[i];
			}
		}
		cout<<sum<<endl<<cnt0<<endl;
		cout<<(ans-tmp*A(cnt0,cnt0)%MOD)%MOD;
	}
	else if(m==n){
		if(cnt0||t[0])cout<<0;
		else {
			else cout<<A(n,n);
		}
	}
}
