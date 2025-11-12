#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int xian=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			xian=i;
			break;
		}
	}
	int lie=(xian-1)/n+1,hang;
	if(lie%2==1){
		hang=(xian-1)%n+1;
	}else{
		hang=2*n+1-xian;
	}
	cout<<lie<<" "<<hang;
	return 0;
}
