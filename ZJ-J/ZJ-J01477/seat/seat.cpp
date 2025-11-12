#include<bits/stdc++.h>
using namespace std;
const int maxn=1e2+5;
int n,m,a[maxn],r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	  scanf("%d",&a[i]);
	r=a[1];
	sort(a+1,a+n*m+1);
	int cnt=n*m,i=1,j=1;
	while(cnt)
	  {
	  	if(a[cnt]==r)
	  	  {
	  	  	printf("%d %d",i,j);
	  	  	return 0;
		  }
	  	if(i&1)
	  	  {
	  	  	if(j<n)
	  	  	  j++;
	  	  	else
	  	  	  i++;
		  }
		else
		  {
		  	if(j>1)
		  	  j--;
		  	else
		  	  i++;
		  }
		cnt--;
	  }
	return 0;
}
