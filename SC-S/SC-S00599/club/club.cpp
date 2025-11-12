#include<bits/stdc++.h>
using namespace std;
const int N=100002;
int t,n;
int a[N][3],d[N],e[N],f[N];
void cmp(int x,int y){
	if(y>x){
		int z=y;
		y=x;
		x=z;
	} 
}
void turn(int y,int z){
	for(int i=y;i<n;i++){
		cmp(a[i][z],a[i+1][z]);
	}
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0;
		int x;
		cin>>n;
		for(int i=0;i<n;i++)
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		turn(0,0);
		for(int i=0;i<n;i++){
			if(i>n/2){
				x=i;
				break;
			}
			ans+=a[i][0]; 
			}
		turn(x,1);
		for(int i=0;i<n;i++){
			if(i>n/2){
				x=i;
				break;
			}
			ans+=a[i][1]; 
			}
		turn(x,2);
		for(int i=0;i<n;i++){
			if(i>n/2){
				x=i;
				break;
			}
			ans+=a[i][3];
			}
		cout<<ans;
	}
	return 0;
}