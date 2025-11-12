#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int N=1e6;
int a[N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if((a[1]+a[2])>a[3])	cout<<1;
		else	cout<<0;
		return 0;
	}
	if(n==4){
		if((a[1]+a[2])>a[3])	sum++;
		if((a[1]+a[2])>a[4])	sum++;
		if((a[2]+a[3])>a[4])	sum++;
		if((a[1]+a[2]+a[3])>a[4])	sum++;
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int l=i+1,r=l+1;
		while(l<=r){
			for(r;r<=n;r++){
				for(l;l<=r-1;l++){
					int cnt_he=a[i];
					for(int j=l;j<=r;i++){
						cnt_he+=a[j];
						if(cnt_he>a[r]){
							sum+=(r-l);
							sum%=mod;
							break;
						}
					}
				}
			}
		}
	}
		
	cout<<sum;
	return 0;
}
