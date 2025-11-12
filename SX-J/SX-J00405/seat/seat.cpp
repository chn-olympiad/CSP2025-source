#include<bits/stdc++.h>
using namespace std;
int a[109],b[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,nm,sit=1,cnt=1,g,x,y;
	cin>>n>>m;nm=n*m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	g=a[1];
	sort(a+1,a+1+nm,cmp);
	for(int i=1;i<=n;i++){
		if(i%2){
			 for(int j=1;j<=n;j++){
				b[j][i]=a[sit];sit++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				b[j][i]=a[sit];sit++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			//cout<<b[i][j]<<" ";
			if(b[i][j]==g)cout<<j<<" "<<i;
		}
		//cout<<endl;
	}
 	return 0;
}

