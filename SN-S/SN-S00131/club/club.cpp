#include<bits/stdc++.h>
using namespace std;
int maxn(int a,int b,int c){
	if(a>=b){
		if(b<=c){
			if(a>=c) return a;
			else return c;
		}
	}else{
		if(b>=c) return b;
		else return c;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int m,n[10010],x=0,y=0,z=0,a[10010][3];
		cin>>m;
		for(int i=1;i<=m;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1,i<=m;i++){
			int l=(a[i][1],a[i][2],a[i][3]);
			if(l==a[i][1] && x<n/2-1){
				n[i]=a[i][1];
				x+=1;
			}else if(l==a[i][2] && y<n/2-1){
				n[i]=a[i][2];
				y+=1;
			}else if(l==a[i][3] && z<n/2-1){
				n[i]=a[i][3];
				z+=1;
			}else if(l==a[i][1] &&  x==n/2){
				for(int j=1;j<=i;j++){
					if(n[j]<a[i][1]){
						n[i]=a[i][1];
						
					}
				}
			}
		}
	}
	return 0;
}
