#include<iostream>
#include<cmath>
using namespace std;
int ans[20],a[500000],b[500000][20],c[1000000][2];
void tttw(int x){
	for(int i=19;i>=0;i--){
		ans[i]=x%2;
		x/=2;
	}
}
int ttte(int x[20]){
	int y;
	for(int i=19;i>=0;i--){
		y+=i*pow(2,19-i);
	}
	return ans[20];
}
int qxor(int x[20],int y[20]){
	int z[20];
	for(int i=0;i<=19;i++){
		if(x[i]!=y[i]){
			z[i]=1;
		}else{
			z[i]=0;
		}
	}
	return z[20];
}
int qk(int x,int y){
	int z[20]={0};
	for(int i=x;i<=y;i++){
		z[20]=qxor(z,b[i]);
	}
	return ttte(z);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,d=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		tttw(a[i]);
		for(int j=19;j>=0;j--){
			b[i][j]=ans[j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			
		}
	}
	return 0;
}
