//王美萱 SN-S00516 西安市曲江第一学校 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,t,maxx1,maxx2;
int b[5];
int cmp(int a,int b){
	return a>b;
}
struct cy{
	int cd;
	int num;
}a[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=3;j++){
			cin>>cy.cd[j];
		}
		if(n==2){
			for(int j=1;j<=3;j++){
				maxx1=max(cy[1].cd[1],max(cy[1].cd[2],cy[i].cd[3]));
				maxx2=max(cy[2].cd[1],max(cy[2].cd[2],cy[2].cd[3]));
				if(maxx1[j]!=maxx2[j]){
					cout<<maxx1+maxx2;
					return 0;
				}						
			}	
		}
		for(int k=1;k<=n;k++){
			for(int j=1;j<=3;j++){
				cout<<maxx1+maxx2;
			}
		}
	}	
	return 0;
}
