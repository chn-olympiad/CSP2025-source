#include<bits/stdc++.h>
using namespace std;
int n,m;
struct k{
	int fen;
	int p=0;
};
k kk[10000];
int z[100][100];
bool pai(k x,k y){
	return x.fen>y.fen;
}
int n1=0,m1=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>kk[i].fen;
		if(i==0){
			kk[i].p=1;
		}
	}
	sort(kk,kk+n*m,pai);
	int f=0;
	int ji=0; 
	while(n1*m1<=(m-1)*(n-1)){
		z[n1][m1]=kk[ji].fen;
		if(kk[ji].p==1){
			cout<<m1+1<<" "<<n1+1;
			return 0;
		}
		ji++;
		if(f%2==0 and n1==n-1 or f%2==1 and n1==0){
			m1++;
			f++;
		}
		else{
			if(f%2==0){
				n1++;
			}
			else{
				n1--;
			}
		}
	}
	return 0;
}
