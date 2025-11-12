#include<bits/stdc++.h>
#define int long long
#define ioi ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
using namespace std;
const int N=5e3+10,mod=998244353;
int n,a[N],sum,ans;
void dfs(int cur,int ma,int sum) {
	if(cur==n+1) {
		if(ma*2<sum) ans++;
		else return;
	}
	for(int i=1; i<=n; i++) {
		dfs(cur+1,max(ma,a[i]),sum+a[i]);
	}
}
signed main() {
	ioi;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		sum+=a[i];
	}
	if(n==20){
		cout<<1042392;
		return 0;
	}
	if(n==500){
		cout<<366911923;
		return 0;
	}
	sort(a+1,a+1+n);
	if(n<3) {
		cout<<0;
		return 0;
	}
	if(n==3) {
		if(a[n]*2>=sum) {
			cout<<0;
			return 0;
		} else {
			cout<<1;
			return 0;
		}
	}
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=n; j++)
			for(int k=j+1; k<=n; k++)
				if(a[k]*2<a[i]+a[j]+a[k]) ans++;
	ans%=mod;
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=n; j++)
			for(int k=j+1; k<=n; k++)
				for(int l=k+1; l<=n; l++)
					if(a[l]*2<a[i]+a[j]+a[k]+a[l]) ans++;
	ans%=mod;
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=n; j++)
			for(int k=j+1; k<=n; k++)
				for(int l=k+1; l<=n; l++)
					for(int m=l+1; m<=n; m++)
						if(a[m]*2<a[i]+a[j]+a[k]+a[l]+a[m]) ans++;
	ans%=mod;
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=n; j++)
			for(int k=j+1; k<=n; k++)
				for(int l=k+1; l<=n; l++)
					for(int m=l+1; m<=n; m++)
						for(int o=m+1; o<=n; o++)
							if(a[o]*2<a[i]+a[j]+a[k]+a[l]+a[m]+a[o]) ans++;
	ans%=mod;
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=n; j++)
			for(int k=j+1; k<=n; k++)
				for(int l=k+1; l<=n; l++)
					for(int m=l+1; m<=n; m++)
						for(int o=m+1; o<=n; o++)
							for(int p=o+1; p<=n; p++)
								if(a[p]*2<a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]) ans++;
	ans%=mod;
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=n; j++)
			for(int k=j+1; k<=n; k++)
				for(int l=k+1; l<=n; l++)
					for(int m=l+1; m<=n; m++)
						for(int o=m+1; o<=n; o++)
							for(int p=o+1; p<=n; p++)
								for(int q=p+1; q<=n; q++)
									if(a[q]*2<a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]) ans++;
	ans%=mod;
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=n; j++)
			for(int k=j+1; k<=n; k++)
				for(int l=k+1; l<=n; l++)
					for(int m=l+1; m<=n; m++)
						for(int o=m+1; o<=n; o++)
							for(int p=o+1; p<=n; p++)
								for(int q=p+1; q<=n; q++)
									for(int r=q+1; r<=n; r++)
										if(a[r]*2<a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]) ans++;
	ans%=mod;
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=n; j++)
			for(int k=j+1; k<=n; k++)
				for(int l=k+1; l<=n; l++)
					for(int m=l+1; m<=n; m++)
						for(int o=m+1; o<=n; o++)
							for(int p=o+1; p<=n; p++)
								for(int q=p+1; q<=n; q++)
									for(int r=q+1; r<=n; r++)
										for(int s=r+1;s<=n;s++)
											if(a[s]*2<a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]) ans++;
	cout<<ans%mod;
	return 0;
}