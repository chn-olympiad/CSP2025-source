#include<bits/stdc++.h>
using namespace std;
long long d(int m){
	long long j=1;
	for (int i=1;i<=m;i++){
		j*=3;
	}
	return j;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	int b[n+1];
	for (int i=1;i<=n;i++){
		long m,max1=0;
		cin>>m;
		int c[m+1][5];
		for (int j=1;j<=m;j++){
			cin>>c[j][1]>>c[j][2]>>c[j][3];
			c[j][4]=1;
		}
		int max2=0;
		c[m][4]=0;
		for (long long p=1;p<=d(m);p++){
			c[m][4]+=1;
			for (int q=m;q>=2;q--){
				if (c[q][4]>3){
					c[q][4]=1;
					c[q-1][4]+=1;
				}
			}
			int c1=0,c2=0,c3=0;
			for (int q=1;q<=m;q++){
				if (c[q][4]==1){
					c1++;
				}
				else if (c[q][4]==2){
					c2++;
				}
				else{
					c3++;
				}
			}
			max2=0; 
			cout<<endl;
			if (c1+c2+c3==m && c1*2<=m && c2*2<=m && c3*2<=m){
				for (int q=1;q<=m;q++){
						max2+=c[q][c[q][4]];
				}
			}
			if (max2>max1){
				max1=max2;
			}
		}
		cout<<max1<<endl;
	}
	return 0;
} 
