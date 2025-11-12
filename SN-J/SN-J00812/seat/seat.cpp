#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[105];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int r=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(a[i]<a[j]) swap(a[i],a[j]);
		}
	}
	int l;
	for(int i=1;i<=n*m;i++) if(a[i]==r) l=i;
	int c=1;
	int cc,rr;
	while(1){
		if(l<c*n+1){
			cc=c-1,rr=c+1;
			break;
		}
		c++;
	}
	if(cc%2!=0) cout<<cc+1<<" "<<n-l+cc*n+1;
	else cout<<cc+1<<" "<<l-cc*n;
	return 0;
}
