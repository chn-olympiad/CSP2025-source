#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,qwe;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	qwe=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==qwe){
			int lie;
			if(i%n!=0){
				lie=i/n+1;
			}
			else{
				lie=i/n;
			}
			if(lie%2!=0){
				if(lie==1){
					cout<<1<<' '<<n;
					return 0;
				}
				else{
					cout<<lie<<' '<<i%n;
				}
			}
			else{
				cout<<lie<<' '<<n-(i%n)+1;
				return 0;
			}
		}
	}
	return 0;
}
