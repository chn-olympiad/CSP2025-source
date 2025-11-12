#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long q,n,t[15],ans;
struct node{
	long long a,b,c,id,h;
}f[100005];
bool cmp1(node x,node y){
	if(x.h==y.h)
	return x.a>y.a;
	return x.h>y.h;
}
bool cmp2(node x,node y){
	if(x.h==y.h)
	return x.b>y.b;
	return x.h>y.h;
}
bool cmp3(node x,node y){
	if(x.h==y.h)
	return x.c>y.c;
	return x.h>y.h;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>q;
	while(q--){
		cin>>n;
		for(int i=1;i<=n;i++){
			f[i].a=0;
			f[i].b=0;
			f[i].c=0;
			f[i].id=0;
			f[i].h=0;
		}
		memset(t,0,sizeof(t));
		ans=0;
		
		for(int i=1;i<=n;i++)
		cin>>f[i].a>>f[i].b>>f[i].c;
	for(int i=1;i<=n;i++)
	if(f[i].a>=f[i].b&&f[i].a>=f[i].c){
	t[1]++;
	f[i].id=1;
	ans+=f[i].a;
	}
	else if(f[i].b>=f[i].a&&f[i].b>=f[i].c){
	t[2]++;
	f[i].id=2;
	ans+=f[i].b;
	}
	else{
	t[3]++;
	f[i].id=3;
	ans+=f[i].c;
	}
		if(t[1]>n/2){
			for(int i=1;i<=n;i++)
				if(f[i].id==1){
				f[i].h=f[i].a-max(f[i].b,f[i].c);
			}
			sort(f+1,f+n+1,cmp1);
			for(int i=n/2+1;i<=t[1];i++){
				if(f[i].b>f[i].c){
				ans+=f[i].b;
				ans-=f[i].a;	
				}
				else{
				ans+=f[i].c;
				ans-=f[i].a;	
				}
			}
		}
		if(t[2]>n/2){
			for(int i=1;i<=n;i++)
				if(f[i].id==2)
				f[i].h=f[i].b-max(f[i].a,f[i].c);
			sort(f+1,f+n+1,cmp2);
			for(int i=n/2+1;i<=t[2];i++){
				if(f[i].a>f[i].c){
				ans+=f[i].a;
				ans-=f[i].b;	
				}
				else{
				ans+=f[i].c;
				ans-=f[i].b;	
				}
			}
		}
		if(t[3]>n/2){
			for(int i=1;i<=n;i++)
				if(f[i].id==3)
				f[i].h=f[i].c-max(f[i].a,f[i].b);
			sort(f+1,f+n+1,cmp3);
			for(int i=n/2+1;i<=t[3];i++){
				if(f[i].b>f[i].a){
				ans+=f[i].b;
				ans-=f[i].c;	
				}
				else{
				ans+=f[i].a;
				ans-=f[i].c;	
				}
			}	
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
