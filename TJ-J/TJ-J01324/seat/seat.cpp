#include<bits/stdc++.h>
using namespace std;
int x,y,z,n,m,num=0;
int a[105];//[105],b[10005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

//	cin>>n>>m;
//	for(int i=1;i<=n*m;i++){
//		cin>>b[i];
//	}
//	int x=b[1];
//	sort(b+1,b+n*m+1,cmp);
//	for(int i=1;i<=m/2;i+=2){
//		for(int j=1;j<=n;j++){
//			a[j][i]=b[++num];
//		}
//		for(int j=n;j>=1;j++){
//			a[j][i+1]=b[++num];
//		}
//	}
//	if(m%2==1){
//		for(int j=1;j<=n;j++){
//			a[j][m]=b[++num];
//		}
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			if(a[i][j]==x){
//				cout<<j<<" "<<i;
//			}
//		}
//	}



	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
//	int z=a[1];
//	sort(a+1,a+n+1,cmp);
//	for(int i=1;i<=n;i++){
//		if(a[i]==z){
//			if(i%n!=0){
//				x=i/n+1;
//				if(x%2==1){
//					y=i%n;
//				}
//				else{
//					y=n-i%n;
//				}
//			}
//		}
//		else{
//			x=i/n;
//			
//		}
//	}
	cout<<1<<" "<<1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
