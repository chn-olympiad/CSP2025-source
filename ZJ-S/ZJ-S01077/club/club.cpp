#include<bits/stdc++.h>
using namespace std;
const int N=1E5+10;
int c[4],b[N];
struct S{
	int x[4];
}a[N];
vector<pair<int,pair<int,int> > > v;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _,n,i,d,t,c1,j;
	scanf("%d",&_);
	while(_--){
		memset(b,0,sizeof(b));
		v.clear();
		c[0]=c[1]=c[2]=c[3]=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			for(j=1;j<=3;j++){
				scanf("%d",&a[i].x[j]);
				if(a[i].x[j]>a[i].x[b[i]]) b[i]=j;
			}
			c[b[i]]++;
		}
		c1=0;
		for(i=1;i<=n;i++) c1+=a[i].x[b[i]];
		if(c[1]<=n/2&&c[2]<=n/2&&c[3]<=n/2) printf("%d\n",c1);
		else{
			if(c[1]>n/2) d=1;
			else if(c[2]>n/2) d=2;
			else d=3;
			for(i=1;i<=n;i++){
				if(b[i]==d){
					t=0;
					for(j=1;j<=3;j++){
						if(j!=d&&a[i].x[j]>a[i].x[t]) t=j;
					}
					v.push_back({a[i].x[b[i]]-a[i].x[t],{i,t}});
				}
			}
			sort(v.begin(),v.end());
			for(i=0;i<c[d]-n/2;i++) c1-=v[i].first;
			printf("%d\n",c1);
		}
	}
	return 0;
}
