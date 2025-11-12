#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[102],aa,ar;
int main(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)aa=a[i];
	}
	int ccfnmsl=n*m;
	sort(a+1,a+ccfnmsl+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(aa==a[i]){
			ar=i;
			break;
		}
	}//cout<<ar;
	cout<<(ar-1)/n+1<<' ';
	int tmp=ar%n;
	if(tmp==0)tmp=n;
	if(((ar-1)/n)&1)cout<<n+1-tmp;
	else cout<<tmp;
}

