#include<bits/stdc++.h>
using namespace std;
int t,z,a1,b1,c1,x1,max_v[305],bigger[305][305],bigger2[305][305],bigger3[305][305],x[305],y[305][305][305];
int po01,po02,po03,sum;
int main() {
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin >> t;//组数
	for(int a=1; a<=t; a++) {
		cin >> x[a];//新成员数量，t组
		for(int b=1; b<=x[a]; b++) {
			for(int c=1; c<=3; c++) {
				cin >> y[a][b][c];
				a1=a;
				b1=b;
				c1=c;
			}
		}
	}
	for(int i=1; i<=t; i++) {
		for(int a=1; a<=t; a++) {
			z=x[a];
			max_v[i]=z/2 ;
		}
	}
	for(int n=1; n<=t; n++) {
		for(int m=1; m<=x[n]; m++) {
			bigger[n][m]=max(y[n][m][1],y[n][m][3]);

		}
	}
	for(int n=1; n<=t; n++) {
		for(int m=1; m<=x[n]; m++) {
			for(int o=1; o<=3; o++) {
				sum=bigger[n][m]+sum;
				
			}
		}
		cout << sum;
	}
	
//	for(int k=1; k<=a1; k++) {
//		for(int i=1; i<=b1; i++) {
//			for(int j=1; j<=c1; j++) {
//				cout << y[k][i][j] << endl;
//			}
//		}
//	}


	return 0;
}

