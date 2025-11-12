#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	int a[n+3][m+3]={1};
	int b[n*m+3]={0};
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	//int mcj=b[1];
	sort(b+1,b+1+n*m);
	int j=n*m;
	int cj[n*m+3];
	for(int i=1;i<=n*m;i++){
		cj[i]=b[j];
		j--;
	}//将成绩从大到小排列
/*
	for(int i=1;i<=n*m;i++){
		cout<<cj[i]<<" ";
	}
*/

	int bs=1;//n的倍数
	for(int i=1;i<=n;i++){
		a[i][1]=cj[i];
	}

	for(int i=n+1;i<=n*m;i++){
		if(i%n==0){
			if(bs%2==1){
				bs++;
				a[1][bs]=cj[i];
			}
			else{
				bs++;
				a[n][bs]=cj[i];
			}
		}
		else{
			int c=n-bs*n;
			if(bs%2==1){
				a[bs+1+1][(n+c)-(2*c-1)+4]=cj[i];
			}
			else{
				a[bs+1][c]=cj[i];
			}
		}

	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			//a[i][j]=mcj;
			//cout<<i<<" "<<j;
			//return 0;
		}
	}








	cout<<endl<<endl;
	for(int i=-5;i<=n+4;i++){
		for(int j=-5;j<=m+4;j++)cout<<a[i][j]<<" ";
		cout<<endl;
	} //测试


	return 0;
}