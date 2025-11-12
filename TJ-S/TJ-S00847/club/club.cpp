#include<bits/stdc++.h>
using namespace std;
int c[100005][3];
int d[100005][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a,b,f=0,e=0;
	cin>>a;
	while(a>0){
		cin>>b;
		for(int i=0;i<b;i++){
			cin>>c[i][0]>>c[i][1]>>c[i][2];
		}
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(c[0][i]+c[1][j]>f&&i!=j){
					f=c[0][i]+c[1][j];
				}
			}
		}
		cout<<f<<endl;
		a--;
		f=0;
	}
	return 0;
}
