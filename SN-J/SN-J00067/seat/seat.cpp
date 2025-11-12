#include <bits/stdc++.h>
using namespace std;
string n;
int main(){
	int n,m,s[10][10],x[110],y=0,S=0;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int k=0;k<(n*m);k++){
		cin>>x[k];
	}
	S=x[0];
	int r=n*m;
	for(int p=r-1;p>0;p--){
		for(int q=0;q<p;q++){
			if(x[q]>x[q+1]){
				y=x[q];
				x[q]=x[q+1];
				x[q+1]=y;
			}
		}
	}
	y=r-1;
	for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=0;j<n;j++){
				s[i][j]=x[y];
				if(x[y]==S){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
				y--;
			}	
		}
		if(i%2==1){
			for(int j=n-1;j>=0;j--){
				s[i][j]=x[y];
				if(x[y]==S){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
				y--;
			}
		}
	}
}
