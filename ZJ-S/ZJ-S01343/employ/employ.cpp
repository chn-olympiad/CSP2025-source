#include<bits/stdc++.h>
using namespace std;
const long long N=505;
const long long mod=998244353;
long long n,ans,m,a[N],b[N],c[N],e[N],g[N],dp[N][N];
char s[N];
void solve1(long long x){
	if(x==n+1){
		long long cnt=0;
		for(int i=1;i<=n;i++){
			if(i-cnt-1<a[b[i]]&&s[i-1]=='1')
			cnt++;
		}
		if(cnt>=m)
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(c[i]==0){
			c[i]=1;
			b[x]=i;
			solve1(x+1);
			c[i]=0;
		}
	}
}
bool ch(){
	for(int i=0;i<n;i++){
		if(s[i]!='1')
		return 0;
	}
	return 1;
}
long long co(int x){
	int sum=0;
	while(x){
		sum+=x%2;
		x/=2;
	}
	return sum;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf(" %s",&s);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	long long cnt=0;
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			cnt++;
			e[cnt]=i+1;
		}
	}
//	cout<<cnt<<endl;
	if(cnt<m){
		printf("%lld",0ll);
		return 0;
	}
	else if(n<=18){
		solve1(1);
		printf("%lld",ans);
		return 0;
	}
	else if(cnt<=18){
		if(cnt<m){
			printf("%lld",0ll);
		}
		long long k,kk,sum,sum1,L;
		sort(a+1,a+n+1);
		for(int i=1;i<(1<<cnt);i++){
			k=co(i);
			kk=1;
//			cout<<k<<endl;
			if(k>=m){
				L=n;
				sum1=0;
//				cout<<i<<"!"<<endl;
				for(int l=cnt;l>0;l--){
					if((i>>(l-1))%2==1){
//						cout<<l<<" "<<e[l]<<" "<<e[l]-1-(k-(kk))<<endl;
//						cout<<a[L]<<endl;
						while(L>0&&a[L]>e[l]-1-(k-(kk))){
						L--;
						sum1++;
						}
						g[kk]=sum1;
//						cout<<sum1<<endl;
//						g[kk]=n-f(e[l]-k+kk-1);
						kk++;
					}
				}
//				cout<<k<<" "<<kk<<endl;
//				sort(g+1,g+kk+1);
				sum=g[1];
				if(sum==0)
				continue;
//				cout<<g[1]<<endl;
				for(int j=2;j<=k;j++){
					if(g[j]<j){
					sum=0;
					break;
					}
//					cout<<g[j]<<endl;
					sum=sum*max(0ll,g[j-1]-j+1)%mod+sum*(g[j]-g[j-1])%mod;
					sum%=mod;
				}
//				cout<<endl;
				ans+=sum;
				ans%=mod;
			}
		}
		printf("%lld",ans);
	}
	else{
		printf("%lld",0ll);
	}
//	else if(ch()){
//		ans=1;
//		long long sum=n;
//		for(int i=n;i>0;i--){
//			if(a[i]==0)
//			sum--;
//		}
//		if(sum<m){
//			printf("%lld",0ll);
//			return 0;
//		}
//		for(long long i=1;i<=sum;i++){
//			ans*=(n-i+1);
//			ans%=mod;
//		}
//		printf("%lld",ans);
//	}
}
