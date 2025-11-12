#include<bits/stdc++.h>
using namespace std;
const int N=5005,M=998244353;
int n,m,a[N],b[N],s[N],res,fac[N];
int kasumi(int x,int y){
	int res=1;
	for(;y;y>>=1,x=1ll*x*x%M){
		if(y&1)res=1ll*res*x%M;
	}
	return res;
}
int C(int n,int m){
	return 1ll*fac[n]*kasumi(fac[n-m],M-2)%M*kasumi(fac[m],M-2)%M;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)b[i]=a[i];
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%M;
	s[0]=1;
	for(int i=1,j=1,ans=1,l=1;i<=n;i++){
		if(b[i]==b[i-1])continue;
		int sum=0,cnt=0;
		while(l<=n&&a[l]==b[i])l++,cnt++;
		while(j<=n&&a[j]<b[i]){
			for(int k=a[n];k>=a[j];k--){
				s[k]=(s[k]+s[k-a[j]])%M;
			}
			j++;
			ans=ans*2%M;
		}
		for(int k=0;k<=b[i];k++){
			sum=(sum-s[k]+M)%M;
		}
		sum=(sum+ans)%M;
		res=(res+1ll*sum*cnt%M)%M;
		if(cnt>1){
			for(int i=3;i<=cnt;i++){
				res=(res+1ll*C(cnt,i)*ans%M)%M;
			}
			res=(res+1ll*C(cnt,2)*(ans-1)%M)%M;
		}
	}
	printf("%d\n",res);
	return 0;
}