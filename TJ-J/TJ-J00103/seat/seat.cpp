#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[101],b[101];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b[1]=a[1];
	sort(a+1,a+(n*m)+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b[1]){
			if(i<=m)cout<<1<<' '<<2;
			else cout<<i/m<<' '<<i/n;
			break;
		}
	}
	return 0;
}
