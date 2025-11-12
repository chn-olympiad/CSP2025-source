#include<bits/stdc++.h>
using namespace std;
int n,m,a[11][11],b,c[20000],q=1,y,t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			c[q]=a[i][j];
			q+=1;
		}
	}
	b=a[1][1];
	q=1;
	for(int i=1;i<=n*m;i++){
		for(int j=2;j<=m*n;j++){
			int w;
			if(c[j]>c[j-1]){
				w=c[j];
				c[j]=c[j-1];
				c[j-1]=w;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				a[i][j]=c[q];
				q++;
			}	
		}
		if(i%2==0){
			for(int j=m;j>=1;j--){
				a[i][j]=c[q];
				q++;
			}	
		}
	}
		for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(a[i][j]==b){
					cout<<i<<" "<<j;
					return 0;
				}
			}	
		}
		if(i%2==0){
			for(int j=m;j>=1;j--){
				if(a[i][j]==b){
					cout<<i<<" "<<j;
					return 0;
				}
			}	
		}
	}
	return 0;
}

