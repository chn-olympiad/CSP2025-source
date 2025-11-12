#include<bits/stdc++.h>
using namespace std;
int a[9][100001],b,c,d,e[100001],f=0;
int ad(int n,int m){
	int w=0;
	for(int i=0; i<=8;i++){
		int h=0;
		for(int j=n; j<=m; j++){
			
			if(a[i][j]!=h){
				h=1;
			}
			else{
				h=0;
			}
		}
		if(h==1) w+=pow(2,i);
	}
	return w;
}
int choose(int n,int m){
	for(int i=n; i<=m; i++){
		if(e[i]==0){
			return 0;
			break;
		}
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>b>>c;
	for(int i=1; i<=b; i++){
		e[i]=1;
		cin>>d;
		for(int j=8; j>=0; j--){
			if(d>=pow(2,j)){
				d-=pow(2,j);
				a[j][i]=1;
			}
		
		}
		
	}
	
	for(int i=1; i<=b; i++){
		for(int j=i; j<=b; j++){
		
			if(choose(i,j) && ad(i,j)==c){
				f++;
		
				for(int z=i; z<=j;z++){
					e[z]=0;
				}
			}
		}
	}
	cout<<f;
	return 0;
}