#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
float a[10011][10011],ccy[11],ccyj[11];
int n,m,k,cnt=0;

int cb(int x,int y){
	int mi=a[x][y],h;
	for(int i=1;i<=k;i++){
		if((int)(a[m+i][x]+a[m+i][y])<=mi&&ccy[i]>=10){
			mi=(int)(a[m+i][x]+a[m+i][y]);
			h=m+i;
		}
	}
	ccyj[h]=1;
	return mi;
}

int main(){
	int x,y,z;
	
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		cin>>x>>y>>z;
		a[x][y]=z;
		a[y][x]=z;
	} 
	float cy,cys;
	for(int i=1;i<=k;i++){
		cin>>cy;
		ccy[i]=cy;
		for(int j=1;j<=m;j++){
			cin>>cys;
			a[m+i][j]=cys;
		}
	}
	
	int mi,s=0,mi1,s1=0;
	for(int i=1;i<m;i++){
		int oo=1;
		while(a[i][i+oo]<1) oo++;
		if(oo+1<=m){
			mi=cb(i,i+oo);
			mi1=a[i][i+oo];
			for(int j=i+oo+1;j<=m;j++){
				if(a[i][j]!=0) {
					mi=min(mi,cb(i,j));
					mi1=min(mi,(int)a[i][j]);
				}
			}
		}
		s+=mi;
		s1+=mi1;
	}
	for(int i=1;i<=k;i++){
		if(ccyj[i]==1) s+=ccy[i];
	}
	cout<<((s<s1)?s:s1);
} 