//SN-J101007  贾章泽 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],c=1,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int x=a[1],j=1;
	sort(a+1,a+n*m+1);
	for(;j<=n*m;j++) if(a[j]==x) break;
	int z=1;
	j=n*m-j+1;
//	cout<<j<<endl;
	while(j--){
		if((r!=n||c%2==0)&&(r!=1||c%2==1)) r+=z;
		else{
			z=-z;
			c++;
		}
//		cout<<c<<" "<<r<<endl;
	}
	cout<<c<<" "<<r;
	return 0; 
}
