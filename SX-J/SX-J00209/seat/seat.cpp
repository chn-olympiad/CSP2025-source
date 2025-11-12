#include<bits/stdc++.h>
using namespace std;
int a[15][15],c[1000];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
	int n,m,p;
	cin>>n>>m;
	int x=1,k=0,v=n*m;
	for(int i=0;i<v;i++){
		cin>>c[i];
	}
	p=c[0];
	sort(c,c+v,cmp);
	for(int i=1;i<=m;i++){
		if(x%2!=0){
			for(int j=1;j<=m;j++){
				a[i][j]=c[k];
				k++;
			}
		}else{
			for(int j=n;j>=1;j--){
			a[i][j]==c[k];
				k++;
			}
		}
		x++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==p){
				cout<<i<<" "<<j;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}