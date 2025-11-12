#include<bits/stdc++.h>
using namespace std;
int d[100005][3];
int e[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int a,b,c,f;
	cin>>a>>b>>c;
	c=10000;
	for(int i=0;i<b;i++){
		cin>>d[i][0]>>d[i][1]>>d[i][2];
		if(d[i][2]<c){
			c=d[i][2];
			f=i;
		}
	}
	e[d[f][0]]=1;
	e[d[f][1]]=1;
	a-=2;
	while(a>0){
		for(int i=0;i<b;i++){
			if((e[d[i][0]]==1&&e[d[i][1]]==0)||(e[d[i][1]]==1&&e[d[i][0]]==0)){
				e[d[i][0]]=1;
				e[d[i][1]]=1;
				a--;
				c+=d[i][2];
			}
		}
	}
	cout<<c;
	return 0;
}
