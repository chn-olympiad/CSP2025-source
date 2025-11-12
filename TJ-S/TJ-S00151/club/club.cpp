#include<bits/stdc++.h>
using namespace std;
struct cy{
	int a;
	int b;
	int c;
}a[100100],b[100100],c[100100];
int n,t,x,y,z,acnt=0,bcnt=0,ccnt=0;
long long sum;
bool amp(cy xx,cy yy){
	return xx.a>yy.a;
}
bool bmp(cy xx,cy yy){
	return xx.b>yy.b;
}
bool cmp(cy xx,cy yy){
	return xx.c>yy.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int ti=1;ti<=t;ti++){
		scanf("%d",&n);
		acnt=0;bcnt=0;ccnt=0;
		
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&x,&y,&z);
			if(x==max(max(x,y),z)){
				acnt++;
				a[acnt].a=x;
				a[acnt].b=y;
				a[acnt].c=z;
				sum+=x;
			}else if(y==max(max(x,y),z)){
				bcnt++;
				b[bcnt].a=x;
				b[bcnt].b=y;
				b[bcnt].c=z;
				sum+=y;
			}else{
				ccnt++;
				c[ccnt].a=x;
				c[ccnt].b=y;
				c[ccnt].c=z;
				sum+=z;
			}
		}
		sort(a+1,a+acnt+1,amp);
		sort(b+1,b+bcnt+1,bmp);
		sort(c+1,c+ccnt+1,cmp);
		while(acnt>n/2||bcnt>n/2||ccnt>n/2){
			while(acnt>n/2){
				if(a[1].b>a[1].c){
					bcnt++;
					b[bcnt]=a[1];
					for(int i=1;i<acnt;i++){
						a[i]=a[i+1];
					}
					acnt--;
					sort(b+1,b+bcnt+1,bmp);
				}else if(a[1].b<a[1].c){
					ccnt++;
					c[ccnt]=a[1];
					for(int i=1;i<acnt;i++){
						a[i]=a[i+1];
					}
					acnt--;
					sort(c+1,c+ccnt+1,cmp);
				}else if(bcnt<=ccnt){
					bcnt++;
					b[bcnt]=a[1];
					for(int i=1;i<acnt;i++){
						a[i]=a[i+1];
					}
					acnt--;
					sort(b+1,b+bcnt+1,bmp);
				}else{
					ccnt++;
					c[ccnt]=a[1];
					for(int i=1;i<acnt;i++){
						a[i]=a[i+1];
					}
					acnt--;
					sort(c+1,c+ccnt+1,cmp);
				}
			}while(bcnt>n/2){
				
				if(b[1].a>b[1].c){
					acnt++; 
					a[acnt]=b[1];
					for(int i=1;i<ccnt;i++){
						b[i]=b[i+1];
					}
					bcnt--;
					sort(a+1,a+acnt+1,amp);
				}else if(b[1].a<b[1].c){
					ccnt++;
					c[ccnt]=b[1];
					for(int i=1;i<bcnt;i++){
						b[i]=b[i+1];
					}
					bcnt--;
					sort(c+1,c+ccnt+1,cmp);
				}else if(acnt<=ccnt){
					acnt++;
					a[acnt]=b[1];
					for(int i=1;i<ccnt;i++){
						b[i]=b[i+1];
					}
					bcnt--;
					sort(a+1,a+acnt+1,amp);
				}else{
					ccnt++;
					c[ccnt]=b[1];
					for(int i=1;i<bcnt;i++){
						b[i]=b[i+1];
					}
					bcnt--;
					sort(c+1,c+ccnt+1,cmp);
				}
			}while(ccnt>n/2){
				if(c[1].a>c[1].b){
					acnt++;
					a[acnt]=c[1];
					for(int i=1;i<ccnt;i++){
						c[i]=c[i+1];
					}
					ccnt--;
					sort(a+1,a+acnt+1,amp);
				}else if(c[1].a<c[1].b){
					bcnt++;
					b[bcnt]=c[1];
					for(int i=1;i<ccnt;i++){
						c[i]=c[i+1];
					}
					ccnt--;
					sort(b+1,b+bcnt+1,bmp);
				}else if(acnt<=bcnt){
					acnt++;
					a[acnt]=c[1];
					for(int i=1;i<ccnt;i++){
						c[i]=c[i+1];
					}
					ccnt--;
					sort(a+1,a+acnt+1,amp);
				}else{
					bcnt++;
					b[bcnt]=c[1];
					for(int i=1;i<ccnt;i++){
						c[i]=c[i+1];
					}
					ccnt--;
					sort(b+1,b+bcnt+1,bmp);
				}
			}
		}
		sum=0;
		for(int i=1;i<=acnt;i++){
			sum+=a[i].a;
		}for(int i=1;i<=bcnt;i++){
			sum+=b[i].b;
		}for(int i=1;i<=ccnt;i++){
			sum+=c[i].c;
		}
		printf("%lld\n",sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
