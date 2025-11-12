#include <bits/stdc++.h>
using namespace std;
int m,n,a[501],b;
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>m>>n>>b;
	int cnt=0,cnt1=m,rs=0;
	for (int i=1;i<=m;i++){
		cin>>a[i];
	}
	if (b==0){
		cout<<0;
		return 0;
	}
	if (n==1){
		while (b/cnt1==0)
		{
			b%=cnt1;
			cnt1--;
		}
		for (int i=1;i<=m;i++){
			if (a[i]>m-cnt1){
				rs++;
			}
		}
		while(b){
			ans*=rs%998244353;
			b/=10;
			rs--;
		}
		cout<<ans;
	}
	else if (n==m){
		while(b){
			if (b/m==0){
				cout<<0;
				return 0;
			}
			b%=m;
			m--;
		}
		cout<<1;
		return 0;
	}
	return 0;
}

