#include<iostream>
using namespace std;
int n,m,x,y,z,xx,yy,zz;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;
		for(int j=1;j<=m;j++){
			cin>>x>>y>>z;
			if(x>y&&x>z) xx+=x;
			else if(y>x&&y>z) yy+=y;
			else if(z>x&&z>y) zz+=z;
		}
	}
	cout<<xx<<endl<<yy<<endl<<zz;
	return 0;
}
