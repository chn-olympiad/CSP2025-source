#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,ans,a[200],numl;
bool cmp(int q,int h){
	return q>h;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++) cin>>a[i];
	ans=a[1];
	sort(a+1,a+1+n*m,cmp);
	numl=1;
	for(i=1;i<=n*m;i++){
		if(i>numl*n) numl++;
		if(ans==a[i]){
			if(numl%2==1) cout<<numl<<" "<<(i-1)%n+1;
			else cout<<numl<<" "<<m-i%n+1;
			return 0;
		}
	}
	return 0;
}
