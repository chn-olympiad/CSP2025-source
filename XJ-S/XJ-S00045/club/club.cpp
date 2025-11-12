#include <iostream>
#include <algorithm>

using namespace std;
struct person{
	int a[3];//ai,j
	int lk;//like
	
};
int n;
int k;
person a[200010];
int clb;//club whose number of members is
// more than n/2 person
int lkcnt[3]={0,0,0};
int fxsum;//number to fix answer
int fx[3][200010]={0};
int fxl[3]={0};
int ans=0;
void rst(){
	n=0;
	clb=0;
	for(int i=0;i<3;i++)lkcnt[i]=0;
	fxsum=0;
	fxl[0]=0;
	fxl[2]=0;
	fxl[1]=0;
	ans=0;
}//reset
int dif(person a){
	int ma=0;
	for(int i=0;i<3;i++){
		if(i!=a.lk)ma=max(ma,a.a[i]);
	}
	return a.a[a.lk]-ma;
}

void inp(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&a[i].a[0],&a[i].a[1],&a[i].a[2]);
		if(a[i].a[0]>=a[i].a[1]&&a[i].a[0]>=a[i].a[2]){
			a[i].lk=0;
		}else if(a[i].a[1]>=a[i].a[0]&&a[i].a[1]>=a[i].a[2]){
			a[i].lk=1;
		}else if(a[i].a[2]>=a[i].a[0]&&a[i].a[2]>=a[i].a[1]){
			a[i].lk=2;
		}else a[i].lk=0;
		lkcnt[a[i].lk]++;
		fx[a[i].lk][fxl[a[i].lk]]=dif(a[i]);
		fxl[a[i].lk]++;
		ans+=a[i].a[a[i].lk];
	}
}//input
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&k);
	
	for(int T=0;T<k;T++){
		rst();
		inp();
		
		if(lkcnt[0]>=lkcnt[1]&&lkcnt[0]>=lkcnt[2]){
			clb=0;
		}else if(lkcnt[1]>=lkcnt[0]&&lkcnt[1]>=lkcnt[2]){
			clb=1;
		}else if(lkcnt[2]>=lkcnt[0]&&lkcnt[2]>=lkcnt[1]){
			clb=2;
		}else clb=0;
		if(lkcnt[clb]>n/2){
			int mt=lkcnt[clb]-n/2;//more than num
			sort(fx[clb]+0,fx[clb]+fxl[clb]);
			for(int i=0;i<mt;i++){
				ans-=fx[clb][i];
			}
		}
		printf("%d\n",ans);
		
		
		
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
