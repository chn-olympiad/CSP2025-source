#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int b,int c){
	if(x>b&&x>c)return 1;
	if(b>x&&b>c)return 2;
	if(c>x&&c>b)return 3;
}
int cmp2(int x1, int b1, int c1) {
	if (x1 > b1 && x1 > c1)
		return x1;
	if (b1 > x1 && b1 > c1)
		return b1;
	if (c1 > x1 && c1 > b1)
		return c1;
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	for(int i=1;i>=t;i++){
		int n;cin>>n;int s=n;int maxx[n+3]={0};int sum[n+3][n+3]={0};
		int a[n+3][4];int m=0;
		for(int k=1;k<=n;k++){
			for(int j=1;j<=3;j++){
				cin>>a[k][j];
			}
		}
		for(int k=1;k<=n;k++){
			for(int j=1;j<=3;j++){
				maxx[k][cmp(a[k][1],a[k][2],a[k][3])]=cmp2(a[k][1], a[k][2], a[k][3]);;
				sum[cmp(a[k][1],a[k][2],a[k][3])]++;
			}
		}for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
			if(sum[k]<=n/2){
				m+=maxx[j][k];
			}
			if(sum[k]>n/2){
				if(maxx[j][k]<maxx[j+1][k])
				swap(maxx[j][k],maxx[j+1][k]);
				
			}
			}
			}
			for(int j=1;j<=n;j++){
				for(int k=1;k<=3;k++){
					for(int l=1;l<=n/2;l++)
					m+=maxx[j][k];
			}
		}
		cout<<m;
		}
			
		
	return 0;
}
