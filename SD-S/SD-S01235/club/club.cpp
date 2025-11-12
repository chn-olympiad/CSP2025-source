#include <bits/stdc++.h>
using namespace std;
int cmp(int x,int y,int z){
	if(x>y&&x>z){
		return x;
	}if(y>z&&y>x){
		return y;
	}if(z>x&&z>y){
		return z;
	}
}
int cmpp(int w,int m){
	return w<m;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a[100000][3],ma=0,c[3]={0},s=0,o[100000],p[100000],q[100000];
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		ma=n/2;
  		for(int j=0;j<n;j++){
   			cin>>a[j][0]>>a[j][1]>>a[j][2];
            s+=cmp(a[j][0],a[j][1],a[j][2]);
			
		}
		cout<<s<<endl;
		s=0;
	}

	

	
	return 0;
}

