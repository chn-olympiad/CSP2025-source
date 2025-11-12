#include<bits/stdc++.h>
using namespace std;
int a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int cnt=0,n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k=1,k2=0;
	for (int i=3;i<=n;i++){
		int ans=0,max1=0;
		while(i!=a[n]){
			for (int j=k;j<=i+k2;j++){
				ans+=a[j];
				max1=max(max1,a[j]);
			}
			k++;
			k2++;
			if (ans>(max1*2))
				cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
