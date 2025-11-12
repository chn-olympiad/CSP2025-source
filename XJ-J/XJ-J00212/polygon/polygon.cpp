#include<bits\stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],cnt,maxn;
int main(){
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		cnt+=a[i];
	}
	if(maxn*2>=cnt)cout<<0;
	else cout<<1;
	return 0;
}
