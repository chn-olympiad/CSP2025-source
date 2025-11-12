#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct Node{
	int a,b,c,v,i;
}a[N];
long long t,n,b[N],lx,ly,lz,sum,ma,mb,mc;
bool cmp(Node xx,Node yy){
	return xx.v<yy.v;
}
bool cmp2(Node xx,Node yy){
	return xx.a<yy.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		sum=lx=ly=lz=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
			if(a[i].a>ma)ma=a[i].a;
			if(a[i].b>ma)mb=a[i].b;
			if(a[i].c>mc)mc=a[i].c;
			a[i].i=i;
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
				++lx;
				sum+=a[i].a;
				b[i]=1;
				a[i].i=i;
				a[i].v=min(a[i].a-a[i].b,a[i].a-a[i].c);
			}else if(a[i].a<=a[i].b&&a[i].b>=a[i].c){
				++ly;
				b[i]=2;
				sum+=a[i].b;
				a[i].v=min(a[i].b-a[i].a,a[i].b-a[i].c);
			}else if(a[i].a<=a[i].c&&a[i].b<=a[i].c){
				++lz;
				b[i]=3;
				sum+=a[i].c;
				a[i].v=min(a[i].c-a[i].a,a[i].c-a[i].a);
			}
		}
		if(mb==0&&mc==0){
			sort(a+1,a+1+n,cmp2);
			for(int i=1;i<=n/2;i++){
				sum-=a[i].a;
			}
			printf("%lld\n",sum);
			continue;
		}
		int c=0;
		if(lx>n/2){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n;i++){
				if(b[a[i].i]==1){
					sum-=a[i].v;
					c++;
					if(c==lx-n/2)break;
				}
			}
		}else if(ly>n/2){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n;i++){
				if(b[a[i].i]==2){
					sum-=a[i].v;
					c++;
					if(c==ly-n/2)break;
				}
			}
		}else if(lz>n/2){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n;i++){
				if(b[a[i].i]==3){
					sum-=a[i].v;
					c++;
					if(c==lz-n/2)break;
				}
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
