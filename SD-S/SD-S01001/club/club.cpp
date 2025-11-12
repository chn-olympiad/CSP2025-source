#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int t,n,v[5],sum;
struct node{
	int x,y;
};
struct data{
	node p[5];
}a[N];
bool cmpn(node xx,node yy){
	return xx.x>yy.x;
}
bool cmpm(data xxx,data yyy){
	if(xxx.p[1].x-xxx.p[2].x!=yyy.p[1].x-yyy.p[2].x) return xxx.p[1].x-xxx.p[2].x>yyy.p[1].x-yyy.p[2].x;
	else return xxx.p[1].x>yyy.p[1].x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int k=1;k<=t;k++){
		sum=v[1]=v[2]=v[3]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].p[1].x,&a[i].p[2].x,&a[i].p[3].x);
			a[i].p[1].y=1;
			a[i].p[2].y=2;
			a[i].p[3].y=3;
			sort(a[i].p+1,a[i].p+4,cmpn);
		}
		sort(a+1,a+1+n,cmpm);
		for(int i=1;i<=n;i++){
			if(v[a[i].p[1].y]+1<=(n/2)){
				v[a[i].p[1].y]++;
				sum+=a[i].p[1].x;
			}
			else{
				sum+=a[i].p[2].x;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
