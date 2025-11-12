#include<bits/stdc++.h>
using namespace std;
struct Seat{
	int x;
	bool flag_x;
};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,maxa,maax,b[n*m+10]={},numa=0;
	cin>>n>>m;
	Seat a[n*m+10]={};
	for(int i=0;i<n*m;i++){
		cin>>a[i].x;
		a[i].flag_x=0;
	}
	for(int i=0;i<n*m;i++){
		maxa=0;
		for(int j=0;j<n*m;j++){
			if(a[j].flag_x==0&&a[j].x>maxa){
				maxa=a[j].x;
				maax=j;
			}
		}
		b[i]=maxa;
		a[maax].flag_x=1;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[numa]==a[0].x){
				cout<<i<<" ";
				if(i%2==0){
					cout<<j+1;
				}
				else{
					cout<<j;
				}
			}
			numa++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
