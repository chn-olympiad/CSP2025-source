#include<bits/stdc++.h>
using namespace std;
int t,n,q,w,e,ans;
struct st1{
	int p,k;
}; 
struct st{
	st1 a,b,c; 
}a[100005];
bool cmp(st a,st b){
	return a.a.p-a.b.p>b.a.p-b.b.p || (a.a.p-a.b.p==b.a.p-b.b.p && a.b.p-a.c.p>b.b.p-b.c.p);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0,q=0,w=0,e=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			st1 x,y,z;
			cin>>x.p>>y.p>>z.p;
			x.k=1,y.k=2,z.k=3;
			if(z.p>y.p)swap(y,z);
			if(y.p>x.p)swap(x,y);
			if(z.p>y.p)swap(y,z);
			a[i]={x,y,z};
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].a.k==1){
				if(q<n/2)ans+=a[i].a.p,q++;
				else if(a[i].b.k==2){
					if(w<n/2)ans+=a[i].b.p,w++;
					else ans+=a[i].c.p,e++;
				}else{
					if(e<n/2)ans+=a[i].b.p,e++;
					else ans+=a[i].c.p,w++;
				}
			}else if(a[i].a.k==2){
				if(w<n/2)ans+=a[i].a.p,w++;
				else if(a[i].b.k==1){
					if(q<n/2)ans+=a[i].b.p,q++;
					else ans+=a[i].c.p,e++;
				}else{
					if(e<n/2)ans+=a[i].b.p,e++;
					else ans+=a[i].c.p,q++;
				}
			}else{
				if(e<n/2)ans+=a[i].a.p,e++;
				else if(a[i].b.k==1){
					if(q<n/2)ans+=a[i].b.p,q++;
					else ans+=a[i].c.p,w++;
				}else{
					if(w<n/2)ans+=a[i].b.p,w++;
					else ans+=a[i].c.p,q++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
