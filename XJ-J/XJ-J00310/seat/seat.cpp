#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==1){
		int a[m+5];
		for(int i=1;i<=m;i++)cin>>a[i];
		int num=a[1];
		sort(a+1,a+m+1);
		for(int i=1;i<=m;i++){
			if(a[i] == num){
				cout<<m-i+1<<" "<<1;
			}
		}
	}
	else if(n>=2){
		int a[n*m+5];
		for(int i=1;i<=n*m;i++)cin>>a[i];
		int num=a[1];
		sort(a+1,a+n*m+1);
		int fa[m+5];
		int fb[m*2+5];
		for(int i=1;i<=m;i++){
			fa[i]=a[i];
		}
		for(int i=2*m;i>m;i--){
			fb[i]=a[i];
		}
		for(int i=1;i<=m;i++){
			if(num==fa[i]){
				cout<<i<<" "<<2;
			}
			else if(num==fb[i]){
				cout<<i<<" "<<1;
			}
		}
	}
	return 0;
}
