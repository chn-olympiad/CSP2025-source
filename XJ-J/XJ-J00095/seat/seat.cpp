#include<bits/stdc++.h>
using namespace std;
const int N=20;
struct aaa{
	int x;
	bool F;
}a[N],b[N][N];
bool cmp(aaa x,aaa y){
	return x.x>y.x;
}
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		if(i==1) a[i].F=true;
		else a[i].F=false;
	}
	sort(a+1,a+n*m+1,cmp);
	int id=1;
	for(int i=1;i<=n;i++){
		if(i%2){
			for(int j=1;j<=m;j++){
				b[j][i].x=a[id++].x;
				b[j][i].F=a[id-1].F;
			}
		}else{
			for(int j=m;j>=1;j--){
				b[j][i].x=a[id++].x;
				b[j][i].F=a[id-1].F;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j].F==true){
				cout<<j<<" "<<i;
				return 0;
			}	
		}
	}
	fclose(stdin);
	fclose(stdout);
}
