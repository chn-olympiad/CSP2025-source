#include <bits/stdc++.h>
#include <cstdio> 
using namespace std;
const int N=10005;
int a[N][N],a1[N*N];
int n,m,x; 
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			x++;
			cin>>a[i][j];
			a1[x]=a[i][j];
		}
	}
	int h=a[1][1];
	sort(a1+1,a1+1+x,cmp);
	x=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			x++;
			a[i][j]=a1[x];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==h){
				cout<<i<<" "<<j<<endl;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
