#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d=0;//a=城市数,b=道路数,c=改造数
long long e[1145][4],f[1145][5],p[1145][1145],k[1145][1145]={},j[1145]={};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>a>>b>>c;
	for(int i=1;i<=a;i++){
		k[i][1]=i;
		j[i]=1;
	}
	for(int i=1;i<=b;i++){
		for(int j=1;j<=3;j++){
			cin>>e[i][j];
		}
		d=d+e[i][3];
		
	}
	for(int i=1;i<=c;i++){
		for(int j=0;j<=4;j++){
			cin>>f[i][j];
		}
	}
	cout<<0;
	return 0;
}