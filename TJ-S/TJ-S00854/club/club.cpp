#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n;
	int a[10001][10001];
	int sum=0;
	int maxn=0;
	int maxb=0;
	int maxc=0;
	for(int z=1;z<=t;z++){
		cin>>n;
		for(int i=1;i<=n;i++){ 
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
	}
	for(int z=1;z<=t;z++){
		for(int i=1;i<=n;i++){ 
			for(int j=1;j<=3;j++){
				if(a[i][2]==0&&a[i][3]==0) {
					maxn=a[1][1];
					if(a[i][1]>a[1][1]) maxn=a[i][1];
					sum=maxn;
				}
				if(a[i][3]==0&&a[i][2]!=0)
					maxn=a[1][1];
					if(a[i][1]>a[1][1]) maxn=a[i][1];
					maxb=a[1][2];
					if(a[i][2]>a[1][2]) maxb=a[i][2];
					sum=maxn+maxb;
				}
				cout<<sum<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
