#include<bits/stdc++.h>
using namespace std;
struct asd{
	int a,b,c,id;
	int ca,jd,cz,zyz;  //ca存储与最优解差距最小的编号 
};
asd a[100001],as[100010],bs[100010],cs[100010];
int suma,sumb,sumc;
bool cmp(asd a,asd b){
	return a.cz<b.cz;
}
int n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		suma=0,sumb=0,sumc=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			a[i].id=i;
			a[i].zyz=max(a[i].a,max(a[i].b,a[i].c));
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
				a[i].jd=1;
			}
			if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
				a[i].jd=2;
			}
			if(a[i].c>=a[i].b&&a[i].c>=a[i].a){
				a[i].jd=3;
			}
			if(a[i].jd==1){
				if(a[i].b>=a[i].c) a[i].ca=2,a[i].cz=a[i].a-a[i].b;
				else a[i].ca=3,a[i].cz=a[i].a-a[i].c; 
				as[++suma]=a[i];
			}
			if(a[i].jd==2){
				if(a[i].a>=a[i].c) a[i].ca=1,a[i].cz=a[i].b-a[i].a;
				else a[i].ca=3,a[i].cz=a[i].b-a[i].c; 
				bs[++sumb]=a[i];
			}
			if(a[i].jd==3){
				if(a[i].a>=a[i].b) a[i].ca=1,a[i].cz=a[i].c-a[i].a;
				else a[i].ca=2,a[i].cz=a[i].c-a[i].b; 
				cs[++sumc]=a[i];
			}
		}
		sort(as+1,as+suma+1,cmp);
		sort(bs+1,bs+sumb+1,cmp);
		sort(cs+1,cs+sumc+1,cmp);
		if(suma>n/2){
			for(int i=1;i<=suma-n/2;i++){
				as[i].zyz=as[i].zyz-as[i].cz;
				if(as[i].ca==2) bs[++sumb]=as[i];
				if(as[i].ca==3) cs[++sumc]=as[i];
				as[i].zyz=0;
			}
		}
		if(sumb>n/2){
			for(int i=1;i<=sumb-n/2;i++){
				bs[i].zyz=bs[i].zyz-bs[i].cz;
				if(bs[i].ca==1) as[++suma]=bs[i];
				if(bs[i].ca==3) cs[++sumc]=bs[i];
				bs[i].zyz=0;
			}
		}
		if(sumc>n/2){
			for(int i=1;i<=sumc-n/2;i++){
				cs[i].zyz=cs[i].zyz-cs[i].cz;
				if(cs[i].ca==2) bs[++sumb]=cs[i];
				if(cs[i].ca==3) as[++suma]=cs[i];
				cs[i].zyz=0;
			}
		}
		int sum=0;
		for(int i=1;i<=suma;i++) sum+=as[i].zyz;
		for(int i=1;i<=sumb;i++) sum+=bs[i].zyz;
		for(int i=1;i<=sumc;i++) sum+=cs[i].zyz;
		cout<<sum<<"\n";
	}
} 
