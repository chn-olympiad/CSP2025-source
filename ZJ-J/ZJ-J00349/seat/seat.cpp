#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],t,h,l,p;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	t=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==t){
			p=n*m-i+1;
			t=1;
			while(p>0){
				if(t==1){
					l++;
					for(int i=1;i<=n;i++){
						p--;
						if(p==0){
							cout<<l<<" "<<i;
							return 0;
						}
					}
					t=2;
				}
				else {
					l++;
					for(int i=1;i<=n;i++){
						p--;
						if(p==0){
							cout<<l<<" "<<n-i+1;
							return 0;
						}
					}
					t=1;
				}
			}
			return 0;
		}
	}
	return 0;
}

