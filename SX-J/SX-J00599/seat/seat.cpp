#include<bits/stdc++.h>
using namespace std;
int n,m,k,l,a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(k==a[i]){
			l=i;
			break;
		}
	cout<<(l+n-1)/n<<" ";
	if((l+n-1)/n%2==1){
		if(l%n==0) cout<<n;
		else cout<<l%n;
	}else cout<<n-l%n+1;
	return 0;
}