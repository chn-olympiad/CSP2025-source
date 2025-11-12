#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,cnt=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if(i==1 && j==1) continue;
			cin>>b;
			if(b>a) cnt++;
		}
	}
	int ans=cnt%n;
	if(ans==0) ans=n;
	cout<<(cnt+n-1)/n<<" ";
	if(((cnt+n-1)/n)%2==1){
		cout<<ans;
	}
	else {
		cout<<n-ans+1;
	}
	return 0;
}
