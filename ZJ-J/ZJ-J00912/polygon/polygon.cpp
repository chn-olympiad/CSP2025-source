#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,ans,maxx=-1;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+1+n);
	if(maxx==1){
		for(int i=3;i<=n;i++){
			int sum=0;
			for(int k=i;k>=3;k--)
			for(int j=1;j<=k-2;j++){
				sum+=j;
			}
			ans+=sum;
			ans%mod;
		}
		cout<<ans%mod;
	}
	else if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
	}
	else if(n==4){
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]>a[k]) ans++;
				}
			}
		}
		if(a[1]+a[2]+a[3]>a[4]) ans++;
		cout<<ans%mod;
	}else if(n==5){
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]>a[k]) ans++;
				}
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++)
					if(a[i]+a[j]+a[k]>a[l]) ans++;
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]>a[5]) ans++;
		cout<<ans%mod;
	}else if(n==6){
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]>a[k]) ans++;
				}
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++)
					if(a[i]+a[j]+a[k]>a[l]) ans++;
				}
			}
		}
		for(int i=1;i<=n-4;i++){
			for(int j=i+1;j<=n-3;j++){
				for(int k=j+1;k<=n-2;k++){
					for(int l=k+1;l<=n-1;l++)
					for(int r=l+1;r<=n;r++)
					if(a[i]+a[j]+a[k]+a[l]>a[r]) ans++;
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]>a[6]) ans++;
		cout<<ans%mod;
	}else if(n==7){
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]>a[k]) ans++;
				}
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++)
					if(a[i]+a[j]+a[k]>a[l]) ans++;
				}
			}
		}
		for(int i=1;i<=n-4;i++){
			for(int j=i+1;j<=n-3;j++){
				for(int k=j+1;k<=n-2;k++){
					for(int l=k+1;l<=n-1;l++)
					for(int r=l+1;r<=n;r++)
					if(a[i]+a[j]+a[k]+a[l]>a[r]) ans++;
				}
			}
		}
		for(int i=1;i<=n-5;i++){
			for(int j=i+1;j<=n-4;j++){
				for(int k=j+1;k<=n-3;k++){
					for(int l=k+1;l<=n-2;l++)
					for(int r=l+1;r<=n-1;r++)
					for(int p=r+1;p<=n;p++)
					if(a[i]+a[j]+a[k]+a[l]+a[r]>a[p]) ans++;
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>a[7]) ans++;
		cout<<ans%mod;
	}
	return 0;
}
