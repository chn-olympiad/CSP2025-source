#include<bits/stdc++.h>
using namespace std;
int a,m,b,cnt=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&a,&m,&a);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a,&a,&b);
		cnt+=b;
	}
	printf("%d",cnt);
	return 0;
}

