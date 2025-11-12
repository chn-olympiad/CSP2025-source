#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[15][15];
bool cmp(int A,int B){
	if(A>B) return 1;
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) 
		cin>>a[i];
	int z=a[1];
	sort(a+1,a+n*m+1,cmp);
	char c='x';
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		b[x][y]=a[i];
		if(c=='x'){
			if(x+1>n) c='r';
			else x++;
		}
		if(c=='s'){
			if(x-1<1) c='r';
			else x--;
		}
		if(c=='r'){
			y++;
			if(x==n) c='s';
			if(x==1) c='x';
		}
	}
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++){
			if(b[i][j]==z){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
} 
