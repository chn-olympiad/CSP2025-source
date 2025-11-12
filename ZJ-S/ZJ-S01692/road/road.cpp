#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,c=0,w;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	while(n--){
		scanf("%d%d%d",&u,&v,&w);
		c=c+w;
	}
	cout<<c+n+m+k-1;
	return 0;
}
