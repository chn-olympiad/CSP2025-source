#include<bits/stdc++.h>
using namespace std;
long long n,a[5006],ans=0,d=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=2;i<n;i++){
		for(int j=0;j<i;j++){
			d+=a[j];
			if(d>a[i]) ans++;
		}
	}
	cout<<ans;
	return 0;
}
