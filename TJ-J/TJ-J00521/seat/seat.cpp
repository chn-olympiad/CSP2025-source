#include <bits/stdc++.h>
using namespace std;
int n,m,c=0,r=0,cj,e=0;
int a[10001]={0};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>cj;
	a[1]=cj;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			e=e+1;
			if(a[e]==cj){
				c=i;
				r=j;
				cout<<c<<' '<<r;
				return 0;
			}
		}
		i++;
		for(int j=m;j>=1;j--){
			e=e+1;
			if(a[e]==cj){
				c=i;
				r=j;
				cout<<c<<' '<<r;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
