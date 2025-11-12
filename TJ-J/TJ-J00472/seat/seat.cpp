#include<bits/stdc++.h>
using namespace std;
long long a[10000000];
long long r,t=1,h=1,l=1,n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a,a+n*m);
	t=n*m-1;
	for(int k=0;l<=m;k++){
		for(int i=1;i<=n;i++){
			if(r==a[t]){
				cout<<l<<' '<<h;
				return 0;
			}
			t--;
			h++;
		}
		l++;
		for(int i=1;i<=n;i++){
			h--;
			if(r==a[t]){
				cout<<l<<' '<<h;
				return 0;
			}
			t--;
		}
		l++;
	}
	return 0;
}
