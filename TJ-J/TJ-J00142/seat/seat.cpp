#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(polygon.in,"r",stdin);
	freopen(polygon.out,"w",stdout);
	int n,m;
	cin>>n>>m;
	int pt[101];
	int pt2[11][11];
	for(int i=1;i<=n*m;i++){
		cin>>pt[i];
	}
	int rt=pt[1];
	if(n==1 && m==1){
		cout<<"1 1";
	}
	int mun=0;
	for(int i=2;i<=n*m;i++){
	for(int j=1;j<i;j++){
			if(pt[i]>=pt[j]){
				int mun=pt[i];
				pt[i]=pt[j];
				pt[j]=mun;
			}
		}
	}
	if(n==2 && m==2){
		for(int i=1;i<=4;i++){
			if(pt[1]==rt){
				cout<<"1 1";
				break;
			}else if(pt[2]==rt){
				cout<<"1 2";
				break;
			}else if(pt[3]==rt){
				cout<<"2 2";
				break;
			}else if(pt[4]==rt){
				cout<<"2 1";
				break;
			}
		}
	}

	return 0;
} 
