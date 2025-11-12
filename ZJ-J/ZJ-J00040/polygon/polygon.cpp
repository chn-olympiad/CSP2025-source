#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5000+5,mod=998244353;
int a[N],fa[N],fb[N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	fa[a[1]]++;
	fa[a[2]]++;
	if(a[1]+a[2]<=5000){
		fa[a[1]+a[2]]++;
	}
	else{
		k++;
	}
	for(int i=3;i<=n;i++){
		ans+=k;
		ans%=mod;
		for(int j=a[i]+1;j<=5000;j++){
			ans+=fa[j];
			ans%=mod;
		}
		int kb=k;
		for(int j=1;j<=5000;j++){
			fb[j]=0;
		}
		fb[a[i]]++;
		for(int j=1;j<=5000;j++){
			fb[j]+=fa[j];
			fb[j]%=mod;
			if(fa[j]!=0){
				if(j+a[i]<=5000){
					fb[j+a[i]]+=fa[j];
					fb[j+a[i]]%=mod;
				}
				else{
					kb+=fa[j];
					kb%=mod;
				}
			}
		}
		for(int j=1;j<=5000;j++){
			fa[j]=fb[j];
		}
		k+=kb;
		k%=mod;
	//	cout<<i<<" "<<ans<<"--\n";
	}
	cout<<ans;
	return 0;
}
/*
5
1 3 5 10 5000
*/
