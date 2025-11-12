#include<bits/stdc++.h>
using namespace std;
int n,t;
struct node{
	int x,y,z,o,p,q,r,s;
}m[123456];
long long ans;
int f[5];
int end;
void s(int i){
	int a=m[i].x,b=m[i].y,c=m[i].z;
	if(a>=b&&a>=c){
		m[i].p=a;
		m[i].r=1;
		if(b>=c){
			m[i].q=b;
			m[i].s=2;
		}
		else {m[i].q=c;m[i].s=3;}
	}
	if(b>=a&&b>=c){
		m[i].p=b;
		m[i].r=2;
		if(a>=c){
			m[i].q=a;
			m[i].s=1;
		}
		else {m[i].q=c;m[i].s=3;}
	}
	if(c>=b&&c>=a){
		m[i].p=c;
		m[i].r=3;
		if(b>=a){
			m[i].q=b;
			m[i].s=2;
		}
		else {m[i].q=a;m[i].s=1;}
	}
	m[i].o=m[i].p-m[i].q;
}
bool cmp(node a,node b){
	return a.o>=b.o;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		f[1]=f[2]=f[3]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&m[i].x,&m[i].y,&m[i].z);
			s(i);
		}
		sort(m+1,m+n+1,cmp);
		for(int i=1;i<=n;i++){
			//cout<<m[i].o<<' '<<m[i].p<<' '<<m[i].q<<' '<<m[i].r<<' '<<m[i].s<<endl;
			if(f[m[i].r]+1<=n/2)
			{
				ans+=m[i].p;
				f[m[i].r]+=1;
			}
			else{
				ans+=m[i].q;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 