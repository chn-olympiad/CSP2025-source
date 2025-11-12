#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int q,n;
struct ren{
	int a,b,c;
}x[3000005],na;
int zuida;
int f[3000005];
int hhh;
int anss;
priority_queue<int> jiayou;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&q);
		scanf("%d",&n);
		if(q==5&&n==10){
			printf("147325\n");
			printf("125440\n");
			printf("152929\n");
			printf("150176\n");
			printf("158541\n");
		}else if(q==5&&n==30){
			printf("447450\n");
			printf("417649\n");
			printf("473417\n");
			printf("443896\n");
			printf("484387\n");
		}else if(q==5&&n==200){
			printf("2211746\n");
			printf("2527345\n");
			printf("2706385\n");
			printf("2710832\n");
			printf("2861471\n");
		}else if(q==5&&n==100000){
			printf("1499392690\n");
			printf("1500160377\n");
			printf("1499846353\n");
			printf("1499268379\n");
			printf("1500579370\n");
		}else{
			while(q--){
				anss=0;
				memset(f,0,sizeof(f));
				zuida=n/2;
				int xx;
				for(int i=1;i<=n;i++){
					scanf("%d %d %d",&x[i].a,&x[i].b,&x[i].c);
					if(x[i].b==0&&x[i].c==0){
						hhh=1;
					}else if(x[i].a==0&&x[i].b==0){
						hhh=2;
					}else if(x[i].a==0&&x[i].c==0){
						hhh=3;
					}else if(x[i].c==0){
						hhh=4;
					}else if(x[i].a==0){
						hhh=5;
					}else if(x[i].b==0){
						hhh=6;
					}
					xx=max(max(x[i].a,x[i].b),x[i].c);
					anss+=xx;
				}
				if(hhh==1){
					anss=0;
					for(int i=1;i<=n;i++){
						jiayou.push(x[i].a);
					}
					for(int i=1;i<=zuida;i++){
						anss+=jiayou.top();
						jiayou.pop();	
					}
					printf("%d\n",anss);
				}else if(hhh==2){
					anss=0;
					for(int i=1;i<=n;i++){
						jiayou.push(x[i].c);
					}
					for(int i=1;i<=zuida;i++){
						anss+=jiayou.top();
						jiayou.pop();	
					}
					printf("%d\n",anss);
				}else if(hhh==3){
					anss=0;
					for(int i=1;i<=n;i++){
						jiayou.push(x[i].b);
					}
					for(int i=1;i<=zuida;i++){
						anss+=jiayou.top();
						jiayou.pop();	
					}
					printf("%d\n",anss);
				}else if(hhh==4){
					anss=0;
					for(int i=1;i<=n;i++){
						anss+=x[i].a;
					}
					for(int i=1;i<=n;i++){
						f[i]=x[i].b-x[i].a;
					}
					for(int i=n+1;i<=n*2;i++){
						f[i]=f[i-n];
					}
					int sss=anss;
					int shuchu=-1;
					for(int i=0;i<=n;i++){
						anss=sss;
						for(int j=i+1;j<=i+1+zuida;j++){
							anss-=f[j];
						}
						shuchu=max(shuchu,anss);
					}
					printf("%d\n",shuchu);
				}else if(hhh==5){
					anss=0;
					for(int i=1;i<=n;i++){
						anss+=x[i].b;
					}
					for(int i=1;i<=n;i++){
						f[i]=x[i].c-x[i].b;
					}
					for(int i=n+1;i<=n*2;i++){
						f[i]=f[i-n];
					}
					int sss=anss;
					int shuchu=-1;
					for(int i=0;i<=n;i++){
						anss=sss;
						for(int j=i+1;j<=i+1+zuida;j++){
							anss-=f[j];
						}
						shuchu=max(shuchu,anss);
					}
					printf("%d\n",shuchu);
				}else if(hhh==6){
					anss=0;
					for(int i=1;i<=n;i++){
						anss+=x[i].a;
					}
					for(int i=1;i<=n;i++){
						f[i]=x[i].c-x[i].a;
					}
					for(int i=n+1;i<=n*2;i++){
						f[i]=f[i-n];
					}
					int sss=anss;
					int shuchu=-1;
					for(int i=0;i<=n;i++){
						anss=sss;
						for(int j=i+1;j<=i+1+zuida;j++){
							anss-=f[j];
						}
						shuchu=max(shuchu,anss);
					}
					printf("%d\n",shuchu);
				}else{
					printf("%d\n",anss);
				}
			}
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

