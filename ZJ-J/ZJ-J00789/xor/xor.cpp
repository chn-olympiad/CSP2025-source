#include <bits/stdc++.h>
using namespace std;
int n,k,s=0;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	vector<int> a(n+1);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	vector<vector<int> > f(n+1,vector<int>(n+1,0));
	for(int i=1; i<=n; i++) {
		f[i][1]=a[i];
	}
	for(int i=1; i<n; i++) {
		for(int j=2; j<=n-i+1; j++) {
			f[i][j]=f[i][j-1]^a[i+j-1];
		}
	}
	/*for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			printf("%d ",f[i][j]);
		}
		printf("\n");
	}

		printf("\n");*/
	for(int i=1; i<=n;i++) {
		for(int j=1;j<=n-i+1;j++) {
			if(f[i][j]==k) {
				i=i+j-1;
				s++;
				break;
			}
		}
	}
	printf("%d",s);
	return 0;
}
/*
5 5
1 8 6 5 10

4 2
2 1 0 3

4 3
2 1 0 3

4 0
2 1 0 3
*/