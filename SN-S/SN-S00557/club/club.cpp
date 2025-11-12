#include<bits/stdc++.h>
using namespace std;
int t;

int n[10];
struct no{
	int i1,i2,i3;
}a[10][100010];
long long maxx(int x,int y,int z){
	return max(max(x,y),z);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >>t;
	for(int i=1;i<=t;i++){
		cin >>n[i];
		long long c=0;
		for(int j=1;j<=n[i];j++){
			cin >>a[i][j].i1>>a[i][j].i2>>a[i][j].i3;
			c+=maxx(a[i][j].i1,a[i][j].i2,a[i][j].i3);
		}
		cout <<c<<endl;
	}
	return 0;
}
