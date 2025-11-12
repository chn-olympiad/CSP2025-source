#include<bits/stdc++.h>
using namespace std;
int n,st;
struct Node{
	int a;
	int b;
	int c;
	int ma;
};
bool cmp1(Node x,Node y){
	return x.a>y.a; 
}
bool cmp2(Node x,Node y){
	return x.b>y.b; 
}
bool cmp3(Node x,Node y){
	return x.c>y.c; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		st=n/2;long long sum=0;
		Node cluber[n+5];
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&cluber[i].a,&cluber[i].b,&cluber[i].c);
			cluber[i].ma=max(cluber[i].a,max(cluber[i].b,cluber[i].c)); 
		}
		if(st==1){
			sum=max(cluber[1].a+0+cluber[2].c,max(cluber[1].a+cluber[2].b+0,max(cluber[2].a+cluber[1].b+0,max(cluber[2].a+0+cluber[1].c,max(0+cluber[1].b+cluber[2].c,0+cluber[2].b+cluber[1].c)))));
		}
		else{
			sort(cluber+1,cluber+1+n,cmp1);
		int num=0;
		for(int i=1;i<=n;i++){
			if(cluber[i].a<cluber[i].ma||cluber[i].ma==-1){
				continue;
			}
			num++;
			sum+=cluber[i].a;
			cluber[i].ma=-1; 
			if(num>=st){
				break;
			}
		}
		//cout<<num<<' '<<sum<<"\n";
		sort(cluber+1,cluber+1+n,cmp2);
		num=0;
		for(int i=1;i<=n;i++){
			if(cluber[i].b<cluber[i].ma||cluber[i].ma==-1){
				continue;
			}
			
			num++;
			sum+=cluber[i].b;
			cluber[i].ma=-1;
			if(num>=st){
				break;
			} 
		}
		//cout<<num<<' '<<sum<<"\n";
		sort(cluber+1,cluber+1+n,cmp3);
		num=0;
		for(int i=1;i<=n;i++){
			if(cluber[i].c<cluber[i].ma||cluber[i].ma==-1){
				continue;
			}
			num++;
			sum+=cluber[i].c;
			cluber[i].ma=-1;
			if(num>=st){
				break;
			} 
		}
		//cout<<num<<' '<<sum<<"\n";
		}
		
		printf("%lld\n",sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
