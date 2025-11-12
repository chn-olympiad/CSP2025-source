#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int score;
	int a[n*m];
	for (int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	score = a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int p;
	for (int i=1;i<=n*m;i++) 
		if (a[i] == score) {
			p = i;
		}
	int r=0,c=1;
	for (int i=1;i<=p;i++){
		if (c%2 == 1){
			r++;
			if (r > n){
				r--;
				c++;
			}
		}
		else{
			r--;
			if (r < 1){
				r++;
				c++;
			}
		}
	}
	printf("%d %d",c,r);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
