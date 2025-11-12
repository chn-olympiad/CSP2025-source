#include<cstdio>
#include<algorithm>
using namespace std;
struct person{
	int a,b,c;
	int z,max1;
}a[100005];
bool cmp(person x,person y){
	if(x.z!=y.z){
		return x.z>y.z;
		//TODO
	}else{
		return x.max1>y.max1;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int n;
		int a1=1,b1=1,c1=1,s=0;
		scanf("%d",&n);
		for(int j=0;j<n;j++){
			int maxn=0,minn=0x7FFFFFFF;
			scanf("%d %d %d",&a[j].a,&a[j].b,&a[j].c);
			maxn=max(max(a[j].a,a[j].b),a[j].c);
			minn=min(min(a[j].a,a[j].b),a[j].c);
			a[j].z=maxn-minn;
			a[j].max1=maxn;
		}
		sort(a,a+n,cmp);
		for(int j=0;j<n;j++){
			if(a[j].a>a[j].b&&a[j].a>a[j].c){
				if(a1>(n/2)){
					a[j].a=-1;
					--j;
					//TODO
				}else{
					++a1;
					s+=a[j].a;
				}
				//TODO
			}
			if(a[j].b>a[j].a&&a[j].b>a[j].c){
				if(b1>(n/2)){
					a[j].b=-1;
					--j;
					//TODO
				}else{
					++b1;
					s+=a[j].b;
				}
				//TODO
			}if(a[j].c>a[j].b&&a[j].c>a[j].a){
				if(c1>(n/2)){
					a[j].c=-1;
					--j;
					//TODO
				}else{
					++c1;
					s+=a[j].c;
				}
				//TODO
			}
		}
		printf("%d\n",s);
		//TODO
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}