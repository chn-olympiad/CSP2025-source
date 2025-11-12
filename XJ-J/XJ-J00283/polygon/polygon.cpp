#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],s=0,ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]; 
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		for(int x=1;x+i-1<=n;x++){
			for(int j=x;j<=i+x-1;j++){
				s+=a[j];
			}
			for(int j=x;j<=i+x-1;j++){
				if(2*j<s){
					if(j==i+x-1) ans++;
				} 
				else break;
			}
		}
	}
	cout<<ans;
	return 0;
}
