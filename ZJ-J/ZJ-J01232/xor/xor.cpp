#include<iostream>
int a[500005],n,k;
int f[500005];//f[i]表示区间【1，i】的权值
int lenq;
int maxn;
struct node{
	int l,r;
}q[500005];
int yihuo(int a,int b){
	int x=a,y=b;
	int sum=0;
	int er=1;
	while(x || y){
		int c=0;
		if(x%2!=y%2){
			c=1;
		}
		sum+=c*er;
		er*=2;
		x/=2;
		y/=2;
	}
	return sum;
}
void xuan(int i,int num){
	for(int j=i+1;j<=lenq;j++){
		if(q[j].l>q[i].r) xuan(j,num+1);
	}
	if(num>maxn) maxn=num;
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	std::cin>>n>>k;
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
	}
	f[1]=a[1];
	for(int i=2;i<=n;i++){
		f[i]=yihuo(f[i-1],a[i]);
	}
	f[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int qz;
			if(i==j) qz=a[i];
			else{
				qz=yihuo(f[i-1],f[j]);
			}
			if(qz==k){
				q[++lenq].l=i;
				q[lenq].r=j;
			}
		}
	}
//	for(int i=1;i<=lenq;i++){
//		for(int j=i+1;j<=lenq;j++){
//			if(q[i].l>q[j].l){
//				node c=q[i];
//				q[i]=q[j];
//				q[j]=c;
//			}else if(q[i].l==q[j].l && q[i].r>q[j].r){
//				node c=q[i];
//				q[i]=q[j];
//				q[j]=c;
//			}
//		}
//	}
	for(int i=1;i<=lenq;i++){
		//std::cout<<q[i].l<<" "<<q[i].r<<std::endl;
		xuan(i,1);
	}
	std::cout<<maxn;
	return 0;
}
