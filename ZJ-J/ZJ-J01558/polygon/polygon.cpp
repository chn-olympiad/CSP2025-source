#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b,c,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b+=a[i];
			c=max(a[i],c);
			if(b>2*c){
				ans++;
				if((b-2*c)+a[i+1]>=2*(a[i+1]-a[i])) ans++;
			}
		}
	}
	cout<<ans;
}