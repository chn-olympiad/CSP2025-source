#include<bits/stdc++.h>
using namespace std;
int a[5000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(int i=3;i<=n;i++){
		for(int l=1;l<i-1;l++){
			for(int r=l+1;r<i;r++){
				int sum=0;
				for(int q=l;q<=r;q++){
					sum+=a[q];
				}
				sum+i;
				if(2*sum>a[i]) ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
