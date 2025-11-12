#include<bits/stdc++.h>
using namespace std;
int n,m,a[30][30],b[1000],c,l=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&b[i]);
	}
	c=b[1];
	l=n*m;
	sort(b+1,b+1+n*m);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[l]==c){
				cout<<i<<' '<<j;
				return 0;
			}
			l--;
		}
		i++;
		for(int j=n;j>=1;j--){
			if(b[l]==c){
				cout<<i<<' '<<j;
				return 0;
			}
			l--;
		}
	}
	return 0;
}
//J-00350