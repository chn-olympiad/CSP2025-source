#include<iostream>
using namespace std;
int x[4]={0,1,0,1};
int y[4]={1,0,-1,0};
int ax,ay,n,m,t,s;
int a[11][11];
int main(){	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cin>>a[i][j];
		}
	}
	t = a[0][0];
	ax  = 1;
	ay  =1;
	for(int i = 0 ;i<n;i++){
		for(int j = 0;j<m;j++){
			if(a[i][j]>t){
				if(ax + x[s]>n||ay+y[s]>m){
					if(s + 1>3){
						s = 0;
					}
					else{
						s +=1 ;
					}
				}
				ax += x[s];
				ay += y[s];
			}
		}
	}
	cout<<ax<<' '<< ay;
	return 0;
}

