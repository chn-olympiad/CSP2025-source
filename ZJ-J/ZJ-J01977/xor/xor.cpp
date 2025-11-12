#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int s[N],n,k,a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	int t=1,ans=0,x=0,y=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) x++;
		else if(a[i]==1) y++;
		s[i]=(s[i-1]^a[i]);
	}
	if(x+y==n&&k<=1){
		if(k==1) cout<<min(x,y);
		else cout<<x/2+y/2;
		return 0;
	}
	for(int r=1;r<=n;r++){
		for(int l=r;l>=t;l--){
			while(s[t-1]==s[t]) t++;
			if((s[l-1]^s[r])==k){
				ans++;
				t=max(t,r+1);
			}
		}
	}
	cout<<ans;
	return 0;
}
