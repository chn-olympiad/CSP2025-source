#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int r,c;
int a[N];
int now,rnk;
signed main(){
//	system("fc seat.out seat.ans");
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>r>>c;
	int n=r*c;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	now=a[1];
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		if(now==a[i]){
			rnk=n-i+1;
			break;
		}
	}
	int lie=(rnk+r-1)/r;
	cout<<lie<<' ';
	if(lie&1){
		cout<<(rnk-1)%r+1;
	}
	else{
		cout<<r-((rnk-1)%r+1)+1;
	}
	return 0;
}

