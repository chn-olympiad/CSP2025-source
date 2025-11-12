#include<bits/stdc++.h>
using namespace std;
bool cmd(int a,int b) {
	return a>b;
}
int n,m;
int a[110],b[15][15];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	int r=a[1],k;
	sort(a+1,a+n*m+1,cmd);
	for(int i=1; i<=n*m; i++) {
		if(a[i]==r) k=i;
	}
	if(n==1) {
		printf("%d 1",k);
		return 0;
	} else if(m==1) {
		printf("1 %d",k);
		return 0;
	}
	int x=1;
	for(int i=1,j=1; 1;) {
		while(i<=n) {
			b[i][j]=x;
			x++;
			i++;

		}
		i=n;
		if(j+1>m) {
			break;
		}
		j++;
		while(i>=1) {
			b[i][j]=x;
			x++;
			i--;

		}
		i=1;
		if(j+1>m) {
			break;
		}
		j++;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(b[i][j]==k) {
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
