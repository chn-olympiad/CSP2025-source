#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,now,rnk;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	now=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(now==a[i]){
			rnk=i;
			break;
		}
	}
	int lie,hang;
	if(rnk%n==0){
		lie=rnk/n;
	}
	else{
		lie=rnk/n+1;
	}
	int pos=rnk%n;
	if(pos==0){
		pos=n;
	}
	if(lie%2==1){
		hang=pos;
	}
	else{
		hang=n-pos+1;
	}
	cout<<lie<<" "<<hang;
}
//AC AC AC I AK csp 33DAI
