#include<bits/stdc++.h>
using namespace std;
int n,m,t,pos;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	t=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			pos=n*m-i+1;
			break;
		}
	}
	int p=pos/n,q=pos%n;
	if(q==0) q=n,p--;
	if(p%2==0) cout<<p+1<<" "<<q;
	else cout<<p+1<<" "<<n+1-q;
	return 0;
}
