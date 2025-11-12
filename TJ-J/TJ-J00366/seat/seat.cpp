#include <bits/stdc++.h>
using namespace std;

int const N=20;
int n,m,k,s;
int a[N*N];

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	scanf("%d %d",&n,&m);
	k=n*m;
	for (int i=1;i<=k;i++) scanf("%d",&a[i]);
	s=a[1];
	sort(a+1,a+k+1);reverse(a+1,a+k+1);
	int cnt=0;
	for (int i=1;i<=m;i++){
		if (i%2){
			for (int j=1;j<=n;j++){
				cnt++;
				if (a[cnt]==s){
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
		else{
			for (int j=n;j;j--){
				cnt++;
				if (a[cnt]==s){
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
	}

	return 0;
}
