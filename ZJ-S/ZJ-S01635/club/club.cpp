#include<bits/stdc++.h>
using namespace std;
long long T,n,t1,t2,t3,i,x,y,z;
struct no{
	int a,b,c;
};
no a[100001],b[100001],c[100001];
struct no2{
	long long a,b,c;
}d[100001];
bool cmp(no t,no w){
	if(t.a-t.b<w.a-w.b)return 1;
	else return 0;
}
void dg(long long x,long long t,long long l){
	int i;
	if(l==1){
		for( i=1;i<=t1;i++)
			if(a[i].a-a[i].b<=d[t].a-max(d[t].b,d[t].c))
				if(a[i].b==d[a[i].c].b){
					b[++t2].a=a[i].b;b[t2].c=a[i].c;
					a[i].a=d[t].a;a[i].b=max(d[t].b,d[t].c);a[i].c=t;
					sort(a+1,a+1+t1,cmp);
					break;
				}
				else {
					c[++t3].a=a[i].b;c[t3].c=a[i].c;
					a[i].a=d[t].a;a[i].b=max(d[t].b,d[t].c);a[i].c=t;
					sort(a+1,a+1+t1,cmp);
					break;
				}
		if(i==t1+1)
				if(d[t].b>=d[t].c){
					b[++t2].a=d[t].b;b[t2].c=x;
				}
				else c[++t3].a=d[t].c,c[t3].c=x;
	}
	else if(l==2){
		for( i=1;i<=t2;i++){
			if(b[i].a-b[i].b<=d[t].b-max(d[t].a,d[t].c))
				if(b[i].b==d[a[i].c].a){
					a[++t1].a=b[i].b;a[t2].c=b[i].c;
					b[i].a=d[t].b;b[i].b=max(d[t].a,d[t].c);b[i].c=t;
					sort(b+1,b+1+t2,cmp);
					break;
				}
				else {
					c[++t3].a=b[i].b;c[t3].c=b[i].c;
					b[i].a=d[t].b;b[i].b=max(d[t].a,d[t].c);b[i].c=t;
					sort(b+1,b+1+t2,cmp);
					break;
				}
		if(i==t2+1)
				if(d[t].c>=d[t].a){
					c[++t3].a=d[t].c;c[t3].c=x;
				}
				else a[++t1].a=d[t].a,a[t1].c=x;
		}
	}
	else{
		for( i=1;i<=t3;i++)
			if(c[i].a-c[i].b<=d[t].c-max(d[t].b,d[t].a))
				if(c[i].b==d[a[i].c].b){
					b[++t2].a=c[i].b;b[t2].c=c[i].c;
					c[i].a=d[t].c;c[i].b=max(d[t].b,d[t].a);c[i].c=t;
					sort(c+1,c+1+t3,cmp);
					break;
				}
				else {
					a[++t1].a=c[i].b;a[t1].c=c[i].c;
					c[i].a=d[t].c;c[i].b=max(d[t].b,d[t].a);c[i].c=t;
					sort(c+1,c+1+t3,cmp);
					break;
				}
		if(i==t3+1)
				if(d[t].b>=d[t].a){
					b[++t2].a=d[t].b;b[t2].c=x;
				}
				else a[++t1].a=d[t].a,a[t1].c=x;	
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;t1=t2=t3=0;
		for(i=1;i<=n;i++){
			cin>>x>>y>>z;
			d[i].a=x;d[i].b=y;d[i].c=z;
			if(x>=y&&x>=z){
				if(t1<n/2){
					a[++t1].a=x,a[t1].b=max(y,z),a[t1].c=i;
					if(t1==n/2)sort(a+1,a+1+t1,cmp);
				}
				else
					dg(x,i,1);
			}
			else if(y>=x&&y>=z){
				if(t2<n/2){
					b[++t2].a=y,b[t2].b=max(x,z),b[t2].c=i;
					if(t2==n/2)sort(b+1,b+1+t2,cmp);
				}
				else
					dg(y,i,2);
			}
			else if(z>=x&&z>=y){
				if(t3<n/2){
					c[++t3].a=z,c[t3].b=max(y,x),c[t3].c=i;
					if(t3==n/2)sort(c+1,c+1+t3,cmp);
				}
				else
					dg(z,i,3);
			}
		}
		long long s=0;
		for(i=1;i<=t1;i++)
			s+=a[i].a;
		for(i=1;i<=t2;i++)
			s+=b[i].a;
		for(i=1;i<=t3;i++)
			s+=c[i].a;
		cout<<s<<endl;
	}
	return 0;
}
