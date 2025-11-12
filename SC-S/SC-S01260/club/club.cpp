#include<bits/stdc++.h>
using namespace std;
int max(int x,int y,int z){
	if(x>y && x>z) return x;
	else{
		if(x>z && x>y) return x;
		else{
			if(y>x && y>z) return y;
			else{
				if(y>z && y>x) return y;
				else{
					if(z>y && z>x) return z;
					else{
						if(z>x && z>y) return z;
					}
				} 
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,y,i,a[100000],b[100000],c[100000];
	cin>>t;
	cin>>n;
	while(t!=0){
		y=0;
			for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			y+=max(a[i],b[i],c[i]);
	    }
	    t--;
	    if(n==2) cout<<y;
	}
	return 0;
}