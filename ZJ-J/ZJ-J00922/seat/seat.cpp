#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s,pos,ans1,ans2,q;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	s=a[1];
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			pos=i;
			break;
		}
	}
	if(pos%n==0)ans1=pos/n,q=n;
	else ans1=pos/n+1,q=pos%n;
	if(ans1%2){
		ans2=q;
	}
	else ans2=n-q+1;
	cout<<ans1<<" "<<ans2;
	return 0;
}
