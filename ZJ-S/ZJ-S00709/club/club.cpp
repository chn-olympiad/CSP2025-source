#include<bits/stdc++.h>
using namespace std;
int t,n,mx,f[5],cnt;
//f[]:max个数 
struct node{
	int a,b,c,x,y,z,op;
	//x:max-次大值 y:max位置 z:次大值位置
}d[100005];
bool cmp(node n,node m){
	return n.x>m.x;
}
void init(){
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&d[i].a,&d[i].b,&d[i].c);
		d[i].op=i;
		int p=6,o,k;
		if(d[i].a>=d[i].b&&d[i].a>=d[i].c)d[i].y=1;
		else if(d[i].b>=d[i].a&&d[i].b>=d[i].c)d[i].y=2;
		else d[i].y=3;
		if(d[i].c<=d[i].a&&d[i].c<=d[i].b)o=3;
		else if(d[i].b<=d[i].a&&d[i].b<=d[i].c)o=2;
		else o=1;
		f[d[i].y]++;
		
	//	printf("d[5].y:%d\n",d[5].y);
//		printf("f[%d]:%d\n",d[i].y,f[d[i].y]);
		p-=d[i].y+o;
//		printf("i=%d,p=%d\n",i,p); //p:right
		d[i].z=p;
		if(d[i].y==1)k=d[i].a;
		else if(d[i].y==2)k=d[i].b;
		else k=d[i].c;
		if(p==1)d[i].x=k-d[i].a;
		else if(p==2)d[i].x=k-d[i].b;
		else if(p==3)d[i].x=k-d[i].c;
	}
}
void print(){
	printf("d:\n");
	printf(" x:");
	for(int i=1;i<=n;i++)cout<<d[i].x<<' ';
	printf("\n y:");
	for(int i=1;i<=n;i++)cout<<d[i].y<<' ';
	printf("\n z:");
	for(int i=1;i<=n;i++)cout<<d[i].z<<' ';
	printf("\n-----------\nf:\n");
	printf("%d %d %d\n",f[1],f[2],f[3]);
	printf("____________\n");
}
void cl(){
	for(int i=1;i<=3;i++)f[i]=0;
	cnt=0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		init();
		mx=n/2;
		int p;
		if(f[1]>=f[2]&&f[1]>=f[3])p=1;
		else if(f[2]>=f[1]&&f[2]>=f[3])p=2;
		else p=3;
	//	printf("p=%d\n",p);
	//	print();
	//	cout<<p<<endl;
/*		if(f[d[p].y]<=mx){
			for(int i=1;i<=n;i++){
				cnt+=max(d[i].a,max(d[i].b,d[i].c));
			//	cout<<cnt<<endl;
			}
			printf("%d\n",cnt);
			cl();
			continue;
		}*/
	//	p=d[p].y;
	//	print();
		sort(d+1,d+1+n,cmp);
	//	print();
		int opp=1;
	//	printf("p=%d\n",p);
		for(int i=1;i<=mx;i++){
			if(p!=d[i].y)mx++;//op_max diff
			if(opp>n)break;
			if(d[i].y==1)cnt+=d[i].a;
			else if(d[i].y==2)cnt+=d[i].b;
			else if(d[i].y==3)cnt+=d[i].c;
		//	printf("mx%d cnt%d op%d y%d\n",mx,cnt,d[i].op,d[i].y);
			opp++;
		}
		for(int i=opp;i<=n;i++){
			if(d[i].y!=p){//can get max
				if(d[i].y==1)cnt+=d[i].a;
				else if(d[i].y==2)cnt+=d[i].b;
				else if(d[i].y==3)cnt+=d[i].c;
			//	printf("d[%d].y:%d cnt%d op%d\n",i,d[i].y,cnt,d[i].op);
			}else if(d[i].z!=p){//cannot get max
				if(d[i].z==1)cnt+=d[i].a;
				else if(d[i].z==2)cnt+=d[i].b;
				else if(d[i].z==3)cnt+=d[i].c;
			//	printf("d[%d].z:%d cnt%d op%d\n",i,d[i].z,cnt,d[i].op);
			}else{
				cnt+=min(d[i].a,min(d[i].b,d[i].c));
			}
			
		}
		printf("%d\n",cnt);
		cl();
	//	for(int i=1;i<=3;i++)printf("%d ",f[i]);
	//	cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
