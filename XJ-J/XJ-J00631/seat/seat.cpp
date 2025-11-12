#include<bits/stdc++.h> 
using namespace std;
int a[11][11],n,m,b[121],bi=1,tmp;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>b[i];
	int xiaor=b[1];
	sort(b+1,b+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++)if(xiaor==b[i])tmp=i;
	int k=1;
	for(int i=1;i<=m;i+=2){
		for(int j=1;j<=n;j++)
			a[i][j]=b[k],k++;
		k+=n;
	}
	k=n+1;
	for(int i=2;i<=m;i+=2){
		for(int j=n;j>=1;j--)
			a[i][j]=b[k],k++;
		k+=n;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
			if(a[i][j]==xiaor){
				cout<<i<<' '<<j;
				return 0;
			}
	}
	return 0;
}

//十年OI一场空，不写freopen见祖宗 
