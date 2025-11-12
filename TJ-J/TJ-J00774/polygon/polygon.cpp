#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[501]={};
	int m[501]={};
	for(int i=0;i<n;i++){
		cin>>a[i];
		m[i]=a[i]*2;
	}
	int num=0;
	int t=1;
	for(int i=3;i<=n;i++){
		num+=t;
		t*=3;
	}
	for(int i=3;i<=n;i++){
		int ans=0;
		for(int j=0;j<i;j++)
			ans+=a[j];
		for(int j=0;j<n-2;j++){
			if(ans<=m[j])
				num--;
			}
		}
	cout<<num;
	return 0;
}
