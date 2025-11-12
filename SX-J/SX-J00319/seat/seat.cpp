#include<bits/stdc++.h>
using namespace std;
int a[110],k[15][15];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m;//n行m列
	scanf("%d%d",&n,&m);
	int cnt=n*m;
	for(int i=1;i<=cnt;i++){
		scanf("%d",&a[i]);
	}
	int p=a[1],l=cnt;//p->a[1]
	sort(a+1,a+1+cnt);
	for(int i=1;i<=m;i++){//单数列从上往下，双数列相反 i列j行
		if(i%2==1){
			for(int j=1;j<=n;j++){
    			k[j][i]=a[l--];
			}
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				k[j][i]=a[l--];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			//cout<<k[i][j]<<" ";
			if(k[i][j]==p){
				cout<<j<<" "<<i;
				return 0;
			}
		}
		//cout<<endl;
	}
	return 0;
}