#include<bits/stdc++.h>
using namespace std;
bool f(int a,int b){
	return a>b;
}
int main(){
	ifstream fin("seat.in");
	ofstream fout("seat.out");
	int a[11][11],d[121],n,m;
	fin>>n>>m;
	for(int i=0;i<n;i++){
		fin>>d[i];
	}
	sort(d,d+n*m,f);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			a[i][j]==d[j*m+i];
		}
	}
	int b=a[0][0];
	for(int i=0;i<m;i++){
		if(m%2==0){
			for(int j=0;j<n;j++){
				if(a[j][i]==b){
					fout<<j<<" "<<i;
					return 0;
				}
			}
		}
		else{
			for(int k=0,j=n-1;j>0;j--,k+=2){
				if(a[j-n+1+k][i]==b){
					fout<<j<<" "<<i;
					return 0;
				}
			}
		}
    }
    fin.close();
	fout.close();
    return 0;
}
