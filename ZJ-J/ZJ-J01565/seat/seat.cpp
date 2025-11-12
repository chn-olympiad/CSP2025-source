#include<bits/stdc++.h>
using namespace std;
int m,n,a,t,w,c,r;
int main(){
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	cin>>n>>m;cin>>a;w=1;
	for(int i=1;i<m*n;i++){
		cin>>t;
		if(t>a)w++;
	}
	c=(w-1)/n+1;
	if(c%2==1)r=(w-1)%m+1;
	else r=n-(w-1)%m;
	printf("%d %d",c,r);
	fclose(stdin);fclose(stdout);
	return 0;
}
