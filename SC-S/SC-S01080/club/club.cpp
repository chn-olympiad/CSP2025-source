#include<bits/stdc++.h>
using namespace std;
long long t,n,sum;
long long o,p,l;
struct A{
	long long q1,w2,e3,mx,mx2,mi;
}a[1000005];
struct Q{
	long long x,y;
}q[500005];
struct W{
	long long xx,yy;
}w[500005];
struct E{
	long long xxx,yyy;
}e[500005];
bool cmp(Q x,Q y){
	return x.y<y.y;
}
bool ccmp(W x,W y){
	return x.yy<y.yy;
}
bool cccmp(E x,E y){
	return x.yyy<y.yyy;
}
long long maax(long long x,long long y){
	if(x>y){
		return x;
	}else{
		return y;
	}
}
long long miin(long long x,long long y){
	if(x<y){
		return x;
	}else{
		return y;
	}
}
long long hh(long long de,long long dr,long long dt){
	long long as[4];
	as[1]=de;
	as[2]=dr;
	as[3]=dt;
	sort(as+1,as+3+1);
	return as[2];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		sum=0;
		o=0,p=0;
		l=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].q1>>a[i].w2>>a[i].e3;
			a[i].mi=miin(a[i].q1,miin(a[i].w2,a[i].e3));
			a[i].mx=maax(a[i].q1,maax(a[i].w2,a[i].e3));
			a[i].mx2=hh(a[i].q1,a[i].w2,a[i].e3)-a[i].mx;
//			cout<<a[i].mx<<" "<<hh(a[i].q1,a[i].w2,a[i].e3)<<" "<<a[i].mi<<endl;
			if(a[i].mx==a[i].q1){
				o++;
				sum+=a[i].mx;
				q[o].x=a[i].q1;
				q[o].y=a[i].mx2;
			}else if(a[i].mx==a[i].w2){
				p++;
				sum+=a[i].mx;
				w[p].xx=a[i].w2;
				w[p].yy=a[i].mx2;
			}else{
				l++;
				sum+=a[i].mx;
				e[l].xxx=a[i].e3;
				e[l].yyy=a[i].mx2;
			}
		}
//		cout<<sum<<endl;
		if(o>n/2){
			sort(q+1,q+o+1,cmp);
			for(int j=n/2+1;j<=o;j++){
				sum+=q[j].y;
				
			}
		}else if(p>n/2){
			sort(w+1,w+p+1,ccmp);
			for(int j=n/2+1;j<=p;j++){
				sum+=w[j].yy;
			}
		}else if(l>n/2){
			sort(e+1,e+l+1,cccmp);
			for(int j=n/2+1;j<=l;j++){
				sum+=e[j].yyy;
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}