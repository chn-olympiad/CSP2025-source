#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a,b,c,ma,mi;
}f[200005];
long long t,n,sum=0,p[10];
bool cmp(node aa,node bb){
	long long qwe,rty;
	if(aa.ma==1){
		qwe=aa.a;
	}else if(aa.ma==2){
		qwe=aa.b;
	}else{
		qwe=aa.c;
	}
	if(bb.ma==1){
		rty=bb.a;
	}else if(bb.ma==2){
		rty=bb.b;
	}else{
		rty=bb.c;
	}
	if(aa.mi==1){
		qwe-=aa.a;
	}else if(aa.mi==2){
		qwe-=aa.b;
	}else{
		qwe-=aa.c;
	}
	if(bb.mi==1){
		rty-=bb.a;
	}else if(bb.mi==2){
		rty-=bb.b;
	}else{
		rty-=bb.c;
	}
	
	return qwe>rty;
}
//long long qqq(node aa){
//	long long qwe,rty;
//	if(aa.ma==1){
//		qwe=aa.a;
//	}else if(aa.ma==2){
//		qwe=aa.b;
//	}else{
//		qwe=aa.c;
//	}
//	if(aa.mi==1){
//		qwe-=aa.a;
//	}else if(aa.mi==2){
//		qwe-=aa.b;
//	}else{
//		qwe-=aa.c;
//	}	
//	return qwe;
//}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(long long iop=1;iop<=t;iop++){
		memset(f,0,sizeof(f));
		memset(p,0,sizeof(p));
		n=0;
		sum=0;
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>f[i].a>>f[i].b>>f[i].c;
			if(f[i].a>=f[i].b&&f[i].a>=f[i].c){
				f[i].ma=1;
			}else if(f[i].b>=f[i].c&&f[i].b>=f[i].a){
				f[i].ma=2;
			}else{
				f[i].ma=3;
			}
			if(f[i].a<=f[i].b&&f[i].a>=f[i].c||f[i].a>=f[i].b&&f[i].a<=f[i].c){
				f[i].mi=1;
			}else if(f[i].b<=f[i].c&&f[i].b>=f[i].a||f[i].b>=f[i].c&&f[i].b<=f[i].a){
				f[i].mi=2;
			}else{
				f[i].mi=3;
			}
		}
		sort(f+1,f+n+1,cmp);
		cout<<f[n].a<<" "<<f[n].b<<" "<<f[n].c<<" "<<qqq(f[n])<<" ";
		for(long long i=1;i<=n;i++){
			
			if(p[f[i].ma]<n/2){
				p[f[i].ma]++;
				if(f[i].ma==1){
					sum+=f[i].a;
				}else if(f[i].ma==2){
					sum+=f[i].b;
				}else{
					sum+=f[i].c;
				}	
			}else{
				p[f[i].mi]++;
				if(f[i].mi==1){
					sum+=f[i].a;
				}else if(f[i].mi==2){
					sum+=f[i].b;
				}else{
					sum+=f[i].c;
				}				
			}
		}
		cout<<sum<<"\n";
	}
	
	return 0;
}

