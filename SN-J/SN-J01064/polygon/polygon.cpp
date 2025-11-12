#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x<y;
}
long long n,a[5005],b[5005],ans=0;
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			for(int k=i;k<=n-j;k++){
				if(a[i]+b[k+j]-b[k-1]>2*a[k+j]){
					ans++;
					ans%=998244353;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
