#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[1007],k,x;
bool cmp(ll aa,ll bb){
	return aa>bb;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++) if(a[i]==k){
		x=i;
		break;
	}
	int ans1=(x+n-1)/n;
	int ans2=((x-1)%n)+1;
	if(ans1%2==0) ans2=n+1-ans2;
	cout<<ans1<<' '<<ans2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
