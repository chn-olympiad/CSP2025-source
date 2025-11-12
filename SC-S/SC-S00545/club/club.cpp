#include<bits/stdc++.h>
using namespace std;
int n,sum,t;
struct node{
    int a=0,b=0,c=0;
}man[100010],a1[100010],b1[100010],c1[100010],mn;
bool cmpa(node x,node y){
    return x.a-max(x.b,x.c)>y.a-max(x.b,x.c);
}
bool cmpb(node x,node y){
    return x.b-max(x.a,x.c)>y.b-max(x.a,x.c);
}
bool cmpc(node x,node y){
    return x.c-max(x.b,x.a)>y.c-max(x.b,x.a);
}
int a2=1,b2=1,c2=1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>man[i].a>>man[i].b>>man[i].c;
		}
		for(int i=1;i<=n;i++){
			if(man[i].a>=man[i].b&&man[i].a>=man[i].c){
        		sum+=man[i].a;
				a1[a2++]=man[i];
        	}
			if(man[i].b>=man[i].c&&man[i].b>=man[i].a){
				sum+=man[i].b;
				b1[b2++]=man[i];
			}
			if(man[i].c>=man[i].b&&man[i].c>=man[i].a){
				sum+=man[i].c;
				c1[c2++]=man[i];
			}
		}
		a2--;
		b2--;
		c2--;
		if(a2>n/2){
			sort(a1+1,a1+1+a2,cmpa);
			for(int i=1;i<=a2-n/2;i++){
				if(a1[i].b>a1[i].c){
					sum+=a1[i].b-a1[i].a;
					b2++;
					b1[b2]=a1[i];
					a1[i]=mn;
				}else{
					sum+=a1[i].c-a1[i].a;
					c2++;
					c1[c2]=a1[i];
					a1[i]=mn;
				}
			}
		}else if(b2>n/2){
			sort(b1+1,b1+1+b2,cmpb);
			for(int i=1;i<=b2-n/2;i++){
				if(b1[i].a>b1[i].c){
					sum+=b1[i].a-b1[i].b;
					a2++;
					a1[a2]=b1[i];
					b1[i]=mn;
				}else{
					sum+=b1[i].c-b1[i].b;
					c2++;
					c1[c2]=b1[i];
					b1[i]=mn;
				}
			}
		}else if(c2>n/2){
			sort(c1+1,c1+1+c2,cmpc);
			for(int i=1;i<=a2-n/2;i++){
				if(a1[i].b>a1[i].b){
					sum+=c1[i].a-c1[i].c;
					a2++;
					a1[a2]=c1[i];
					c1[i]=mn;
				}else{
					sum+=c1[i].b-c1[i].c;
					b2++;
					b1[b2]=c1[i];
					c1[i]=mn;
				}
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}