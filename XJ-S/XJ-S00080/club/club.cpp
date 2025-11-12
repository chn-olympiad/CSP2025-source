#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][4];
int max_n,flag;

int main () {
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(max_n<a[i][j]){
					max_n=a[i][j];
				}
			}
			flag+=max_n;
			max_n=0;
			printf("%d\n",flag);
			break;
		}
	} 
	return 0;
} 

