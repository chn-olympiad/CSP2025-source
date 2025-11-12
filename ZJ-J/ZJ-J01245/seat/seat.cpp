#include<bits/stdc++.h>
using namespace std;
int a[1010],b[1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n*m+1);
	int cnt=1;
	for(int i=n*m;i>=1;i--){
		if(b[i]==a[1]){
			cnt=i;
			break;
		}
	}
	cnt=n*m-cnt+1;
	int k=(cnt+n-1)/n;
	cout<<k<<" ";
	if(k%2){
		int ans=cnt%n;
		if(ans==0){
			ans=n;
		}
		cout<<ans;
	}else{
		int ans=cnt%n;
		if(ans==0){
			ans=n;
		}
		cout<<n-ans+1;
	}
	return 0;
}
