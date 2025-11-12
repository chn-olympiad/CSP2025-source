#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;
	int a[200][200];
	int num[2000];
	
	cin>>t;
	for(int k=0;k<t;k++){
		int d[4][2000]={0};
		int q[4]={1,1,1,1};
		cin>>n;
		for(int i = 1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>a[i][2] && a[i][1]>a[i][3]){
				d[1][q[1]] = a[i][1];q[1]++;continue;
			}
			if(a[i][2]>a[i][1] && a[i][2]>a[i][3]){
				d[2][q[2]] = a[i][2];q[2]++;continue;
			}
			if(a[i][3]>a[i][2] && a[i][3]>a[i][1]){
				d[3][q[3]] = a[i][3];q[3]++;continue;
			}
			
		}
		for(int u = 1;u<=3;u++){
			if(q[u] <= n/2){
				for(int j = 1;j <= n/2;j++) num[k] += d[u][j];
			}
			else{
				for(int j = n/2;j<=q[u];j++){
					for(int h=1;h<j;h++){
						if(d[u][j]>d[u][h]){
							int p;
							p = d[u][j];
							d[u][j] = d[u][h];
							d[u][h] = p;
						}
					}
				}
				for(int j = 1;j<=2;j++) num[k] += d[u][j];
			}
		}
	}
	for(int k=0;k<t;k++){
		cout<<num[k]<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}