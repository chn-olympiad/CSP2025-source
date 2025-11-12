#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,ans,sum,cnt;
int a[5005];
map<int,long long>jc;
/*int dfs(int num1,int num2,int s,int maxx,int dep){
	if(dep==n+1){
		return ans%mod;
	}
	for(int i=num2+1;i<=n;i++){
		int k=upper_bound(a+num,a+n+1,s)-a;
		if(k<=n) ans+=n-k+1;
	}
}*/
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]==1) cnt++;
		sum+=a[i];
	}
	jc[1]=1;
	for(int i=2;i<=n;i++){
		jc[i]=i*jc[i-1];
	}
	sort(a+1,a+n+1);
	if(n<3){
		cout << 0;
		return 0;
	}
	if(n==3){
		if(sum>a[n]) cout << 1;
		else cout << 0;
		return 0;
	}
	if(cnt==n){
		for(int i=2;i<=n;i++){
			for(int j=1;j<=i;j++){
				ans=(ans+jc[i]/jc[i-j]*(n-i)%mod);
			}
		}
		cout << ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int s=a[i]+a[j];
			int q=lower_bound(a+j+1,a+n+1,s)-a;
			if(q<=n+1) ans+=q-j-1;
			for(int k=j+1;k<=n;k++){
				s=a[i]+a[j]+a[k];
				int q=lower_bound(a+k+1,a+n+1,s)-a;
				if(q<=n+1) ans+=q-k-1;
				for(int o=k+1;o<=n;o++){
					s=a[i]+a[j]+a[k]+a[o];
					int q=lower_bound(a+o+1,a+n+1,s)-a;
					if(q<=n+1) ans+=q-o-1;
					for(int p=o+1;p<=n;p++){
						s=a[i]+a[j]+a[k]+a[o]+a[p];
						int q=lower_bound(a+p+1,a+n+1,s)-a;
						if(q<=n+1) ans+=q-p-1;
						for(int u=p+1;u<=n;u++){
							s=a[i]+a[j]+a[k]+a[o]+a[p]+a[u];
							int q=lower_bound(a+u+1,a+n+1,s)-a;
							if(q<=n+1) ans+=q-u-1;
							for(int r=u+1;r<=n;r++){
								s=a[i]+a[j]+a[k]+a[o]+a[p]+a[u]+a[r];
								int q=lower_bound(a+r+1,a+n+1,s)-a;
								if(q<=n+1) ans+=q-r-1;
								for(int e=r+1;e<=n;e++){
									s=a[i]+a[j]+a[k]+a[o]+a[p]+a[u]+a[r]+a[e];
									int q=lower_bound(a+e+1,a+n+1,s)-a;
									if(q<=n+1) ans+=q-e-1;
									for(int w=e+1;w<=n;w++){
										s=a[i]+a[j]+a[k]+a[o]+a[p]+a[u]+a[r]+a[e]+a[w];
										int q=lower_bound(a+w+1,a+n+1,s)-a;
										if(q<=n+1) ans+=q-w-1;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << ans%mod;
	return 0;
}
