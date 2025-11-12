#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,c,d[105],e[15][15],h=0;
	bool f,g;
	cin>>a>>b>>c;
	d[1]=c;
	h=a*b;
	for(int i=2;i<=a*b;i++) cin>>d[i];
	sort(d+1,d+a*b+1);
	for(int i=1;i<=b;i++){
		if(f==0){
			f=1;
			for(int j=1;j<=a;j++)e[j][i]=d[h--];
		}
		else{
			f=0;
			for(int j=a;j>=1;j--)e[j][i]=d[h--];
		}
	}
	for(int i=1;i<=b;i++){
		for(int j=1;j<=a;j++){
			if(e[i][j]==c){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}