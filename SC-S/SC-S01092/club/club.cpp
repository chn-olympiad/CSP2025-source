#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
const int inf=0x3f3f3f3f;

int T;
int n;
struct node{
	int c1,c2,c3;
}a[N];
bool cmp(node x,node y){
	if(x.c1!=y.c1)return x.c1>y.c1;
	if(x.c2!=y.c2)return x.c2>y.c2;
	return x.c3>y.c3;
}

struct dt{
	int w,id;
};
bool cmp2(dt x,dt y){
	return x.w>y.w;
}

int ck(int a,int b,int c){
	if(a>=b && a>=c)return 1;
	if(b>=a && b>=c)return 2;
	if(c>=a && c>=b)return 3;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			a[i].c1=-1;
			a[i].c2=-1;
			a[i].c3=-1;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i].c1>>a[i].c2>>a[i].c3;
		}
		sort(a+1,a+n+1,cmp);
		int ans=0,m=n/2,p[3]={m,m,m};
		for(int i=1;i<=n;i++){
			if(!p[0] && !p[1] && !p[2])break;
			int x=a[i].c1,y=a[i].c2,z=a[i].c3;
			dt c[3]={{x,0},{y,1},{z,2}};sort(c,c+3,cmp2);
			for(int k=0;k<3;k++){
				if(p[c[k].id]){
					ans+=c[k].w,p[c[k].id]--;
					break;
				}
			}
		}cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}