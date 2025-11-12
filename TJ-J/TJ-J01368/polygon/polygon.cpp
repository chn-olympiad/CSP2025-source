#include <bits/stdc++.h>
using namespace std;
int n,a[5005],ans,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n); 
	for(int i=0;i<n;i++){
		for(int j=3;j<=n-i;j++){
			for(int k=i;k<i+j;k++){
				sum+=a[k];
			}
			if(sum>a[i+j]*2) cout<<i<<' '<<j<<endl;ans++;
			sum=0;
		}
	}
	cout<<ans;
	return 0;
}
