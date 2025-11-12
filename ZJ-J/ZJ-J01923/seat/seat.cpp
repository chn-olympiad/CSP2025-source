#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s[105],r,k,h,l;
	scanf("%d %d %d",&n,&m,&r);
	s[1]=r;
	for(int i=2;i<=n*m;i++)
		scanf("%d",&s[i]);
	sort(s+1,s+n*m+1);
	for(int i=1;i<=n*m;i++)
		if(s[i]==r){
			k=n*m-i+1;
			break;
		}
	l=(k+n-1)/n;
	if(l%2)
		h=(k-1)%n+1;
	else
		h=n-(k-1)%n;
	printf("%d %d\n",l,h);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
