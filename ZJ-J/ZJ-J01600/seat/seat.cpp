#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m,A,a[113];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>A;
	for(int i = 1;i<n*m;i++)cin>>a[i];
	sort(a+1,a+n*m,cmp);
	if(a[n*m]>A){
		if(m&1)cout<<m<<' '<<n<<endl;
		else cout<<m<<' '<<1<<endl;
		return 0;
	}
	int pos = 0;
	for(int j = 1;j<=m;j+=2){
		for(int i = 1;i<=n;i++){
			if(a[++pos]<A){
				cout<<j<<' '<<i<<endl;
				return 0;
			}
		}
		for(int i = n;i>=1;i--){
			if(a[++pos]<A){
				cout<<j+1<<' '<<i<<endl;
				return 0;	
			}
		}
	}
	return 0;
}

