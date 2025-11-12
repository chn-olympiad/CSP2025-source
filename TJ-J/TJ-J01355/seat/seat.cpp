#include <bits/stdc++.h>
using namespace std;
int a[100005],t[105],shu[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,minn=1e9,maxn=-1e9,num=1;;
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
		minn=min(minn,a[i]);
		maxn=max(maxn,a[i]);
	}
	if(a[1]==maxn) {
		cout<<1<<" "<<1;
		return 0;
	}
	if(a[1]==minn) {
		cout<<n<<" "<<m;
		return 0;
	}
	for(int i=1;i<=n*m;++i){
		t[a[i]]++;
	}
	for(int i=100;i>=1;--i){
		if(t[i]!=0) {
			shu[num]+=i;
			num++;
		}
	}
	int ans=0,z;
	for(int i=1;i<=num;++i){
		if(shu[i]==a[1]){
			for(int j=1;j<=n*m;++j){
				if(ans+n>=i) {
					cout<<j<<" ";
					break;
				}
				ans+=n;
				z=j;
			}
			if(i%n==0) cout<<n;
			else cout<<i%n;
			return 0;
		}
	}
	return 0;
}
