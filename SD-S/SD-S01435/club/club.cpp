#include<bits/stdc++.h>
using namespace std;
int T,n,o,b[4];
pair<int,int> c[4];
struct S{
	int a[4];
	bool operator < (const S &A) const{
		int x=a[1],y=a[2],z=a[3],X=A.a[1],Y=A.a[2],Z=A.a[3];
		return max({x,y,z})-(x+y+z-max({x,y,z})-min({x,y,z}))>max({X,Y,Z})-(X+Y+Z-max({X,Y,Z})-min({X,Y,Z}));
	}
}a[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		o=0;
		memset(b,0,sizeof(b));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i].a[1],&a[i].a[2],&a[i].a[3]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				c[j]={a[i].a[j],j};
			}
			sort(c+1,c+4);
			reverse(c+1,c+4);
			for(int j=1;j<=3;j++){
				if(b[c[j].second]<n/2){
					o+=c[j].first;
					b[c[j].second]++;
					break;
				}
			}
		}
		printf("%d\n",o);
	}
	return 0;
}

