#include<bits/stdc++.h>
using namespace std;
int a[5002];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,s=0,q=0;
	cin>>n;
	q=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int k=n;k>=1;k--){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[k]!=a[i] && a[i]!=a[j] && a[k]!=a[j] && a[k]!=0 && a[i]!=0 && a[j]!=0){
					if(a[i]+a[j]>a[k]){
						s+=1+(q-3);
						a[i]=0;
						a[j]=0;
						q-=2;
					}
				}
				else{
					continue;
				}
			}
		}
	}
	if(s>998244353){
		cout<<s%998244353;
	}
	else{
		cout<<s;
	}
	return 0;
}
