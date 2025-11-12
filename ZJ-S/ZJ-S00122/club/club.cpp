#include<bits/stdc++.h>
using namespace std;
int t,n,nn,ff[10],a[100005][5],sum[5],f[5][50005],s[50005];
long long ans;
long long work(int x){
	long long num=0;
	if(x>n){
		long long num=0;
		for(int i=1;i<=3;i++){
			for(int j=1;j<=sum[i];j++){
				num+=(long long)a[f[i][j]][i];
			}
		}
		return num;
	}
	for(int i=1;i<=3;i++){
		if(sum[i]<nn){
			sum[i]++;
			f[i][sum[i]]=x;
			num=max(num,work(x+1));
			f[i][sum[i]]=0;
			sum[i]--;
		}
	}
	return num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int T=1;T<=t;T++){
		scanf("%d",&n);
		nn=n/2;
		ff[1]=0;
		ff[2]=0;
		ff[3]=0;
		ff[4]=0;
		ff[5]=0;
		ff[6]=0;
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2]==a[i][3]&&a[i][2]==0) ff[1]++;
			if(a[i][1]==a[i][3]&&a[i][1]==0) ff[2]++;
			if(a[i][1]==a[i][2]&&a[i][1]==0) ff[3]++;
			if(a[i][1]==0) ff[4]++;
			if(a[i][2]==0) ff[5]++;
			if(a[i][3]==0) ff[6]++;
		}
		if(ff[1]==n){
			for(int i=1;i<=n;i++){
				s[i]=a[i][1];
			}
			sort(s+1,s+1+n);
			for(int i=n;i>=n-nn+1;i--) ans+=(long long)s[i];
			printf("%lld\n",ans);
			continue;
		}else if(ff[2]==n){
			for(int i=1;i<=n;i++){
				s[i]=a[i][2];
			}
			sort(s+1,s+1+n);
			for(int i=n;i>=n-nn+1;i--) ans+=(long long)s[i];
			printf("%lld\n",ans);
			continue;
		}else if(ff[3]==n){
			for(int i=1;i<=n;i++){
				s[i]=a[i][3];
			}
			sort(s+1,s+1+n);
			for(int i=n;i>=n-nn+1;i--) ans+=(long long)s[i];
			printf("%lld\n",ans);
			continue;
		}else if(ff[6]==n){
			for(int i=1;i<=n;i++){
				ans+=(long long)a[i][2];
				s[i]=a[i][1]-a[i][2];
			}
			sort(s+1,s+1+n);
			for(int i=n;i>=n-nn+1;i--) ans+=(long long)s[i];
			printf("%lld\n",ans);
			continue;
		}else if(ff[5]==n){
			for(int i=1;i<=n;i++){
				ans+=(long long)a[i][1];
				s[i]=a[i][3]-a[i][1];
			}
			sort(s+1,s+1+n);
			for(int i=n;i>=n-nn+1;i--) ans+=(long long)s[i];
			printf("%lld\n",ans);
			continue;
		}else if(ff[4]==n){
			for(int i=1;i<=n;i++){
				ans+=(long long)a[i][2];
				s[i]=a[i][3]-a[i][2];
			}
			sort(s+1,s+1+n);
			for(int i=n;i>=n-nn+1;i--) ans+=(long long)s[i];
			printf("%lld\n",ans);
			continue;
		}else{
			ans=work(1);
			printf("%lld\n",ans);
		}
	}
	return 0;
}