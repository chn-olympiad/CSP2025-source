#include<bits/stdc++.h>
using namespace std;
long long x[100010][10];
int y[10][100010];
long long z[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		memset(y,0,sizeof(y));
		memset(z,0,sizeof(z));
		int n;
		cin>>n;
		long long i=0,j=0,k=0,l=0;
		for(int c=0;c<n;c++){
			for(int d=0;d<3;d++){
				cin>>x[c][d];
			}
			if(x[c][0]>=x[c][1]&&x[c][0]>=x[c][2]){
				y[0][i++]=c;
				l+=x[c][0];
			}
			else if(x[c][1]>=x[c][0]&&x[c][1]>=x[c][2]){
				y[1][j++]=c;
				l+=x[c][1];
			}
			else if(x[c][2]>=x[c][0]&&x[c][2]>=x[c][1]){
				y[2][k++]=c;
				l+=x[c][2];
			}
		}
		int ii=0;
		if(i>n/2){
			ii=i;
			for(int c=0;c<i;c++){
				z[c]=x[y[0][c]][0]-max(x[y[0][c]][1],x[y[0][c]][2]);
			}
		}
		else if(j>n/2){
			ii=j;
			for(int c=0;c<j;c++){
				z[c]=x[y[1][c]][1]-max(x[y[1][c]][0],x[y[1][c]][2]);
			}
		}
		else if(k>n/2){
			ii=k;
			for(int c=0;c<k;c++){
				z[c]=x[y[2][c]][2]-max(x[y[2][c]][1],x[y[2][c]][0]);
			}
		}
		if(ii==0){
			cout<<l<<"\n";
		}
		else{
			sort(z,z+ii);
			for(int c=0;c<ii-n/2;c++){
				l-=z[c];
			}
			cout<<l<<"\n";
		}
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
