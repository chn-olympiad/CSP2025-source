#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,t,a[105];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			t=i;
			break;
		}
	}
	cout<<(t-1)/n+1<<" ";
	int s=t-((t-1)/n)*n;
	if(((t-1)/n+1)%2==0) cout<<n-s+1;
	else cout<<s;
}
