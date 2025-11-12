//缑致玮-SN-S00580-延安新区第三中学 
#include<bits/stdc++.h>
using namespace std;
string a[5000010];
string b[5000010];
string c[5000010];
string d[5000010];

int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","r",stdout);
	int n,m,yn,y1.y2;
	cin>>n>m;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	for(int j=0;j<m;j++){
		cin>>c[j]>>d[j];
	}
	for(int i=0;i<n;i++){
		int o-=a.size;
		for(int k=0;k<o;k++){
			if(c[i][o]!=d[i][o]&&w=2){
				y1+=c[i][o];
				y2+=d[i][o];
			}
			if(c[i][o]==d[i][o]&&w=2){
				w=1;
			}
			if(c[i][o]!=d[i][o]&&w=0){
				y1+=c[i][o];
				y2+=d[i][o];
				w=2;
			}
		}
	}
	return 0;
}
