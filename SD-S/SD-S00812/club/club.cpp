#include<bits/stdc++.h>
using namespace std;
/*struct k{
	int a,b,c;
}a1[100005],b1[100005],c1[100005];
bool cmp1(k a1,k b1) {
	if(a1.a>b1.a) return 1;
	else return 0;
}
bool cmp2(k a1,k b1) {
	if(a1.b>b1.b) return 1;
	else return 0;
}
bool cmp3(k a1,k b1) {
	if(a1.c>b1.c) return 1;
	else return 0;
}*/
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		int n,sum=0,a=0,b=0,c=0;
		cin>>n;
		int a1[n],b1[n],c1[n];
		for(int i=0;i<n;i++) cin>>a1[i]>>b1[i]>>c1[i]; 
		for(int i=0;i<n;i++) {
			if(b1[i]==0&&c1[i]==0) {
				sum+=a1[i];
				continue;
			}
			if(a1[i]==max({a1[i],b1[i][i],c1[i]})&&a<=n/2) a++,sum+=a1[i];
			else if(a1[i]==max({a1[i],b1[i][i],c1[i]})&&b1[i][i]==max(b1[i][i],c1[i])&&a>n/2) b++,sum+=b1[i];
			else if(a1[i]==max({a1[i],b1[i],c1[i]})&&c1[i]==max(b1[i],c1[i])&&a>n/2) c++,sum+=c1[i];
			if(b1[i]==max({a1[i],b1[i],c1[i]})&&b<=n/2) b++,sum+=b1[i];
			else if(b1[i]==max({a1[i],b1[i],c1[i]})&&a1[i]==max(a1[i],c1[i])&&b>n/2) a++,sum+=a1[i];
			else if(b1[i]==max({a1[i],b1[i],c1[i]})&&c1[i]==max(a1[i],c1[i])&&b>n/2) c++,sum+=c1[i];
			if(c1[i]==max({a1[i],b1[i],c1[i]})&&c<=n/2) c++,sum+=c1[i];
			else if(c1[i]==max({a1[i],b1[i],c1[i]})&&a1[i]==max(a1[i],b1[i])&&c>n/2) a++,sum+=a1[i];
			else if(c1[i]==max({a1[i],b1[i],c1[i]})&&b1[i]==max(a1[i],b1[i])&&c>n/2) b++,sum+=b1[i];
		}
		cout<<sum<<"\n";
		/*int n,av=0,bv=0,cv=0,sum=0;
		cin>>n;
		for(int i=1;i<=n;i++) {
			int l,r,u;
			cin>>l>>r>>u;
			if(l==max({l,r,u})) a1[av].a=l,a1[av].b=r,a1[av].c=u,av++;
			else if(r==max({l,r,u})) b1[bv].a=l,b1[bv].b=r,b1[bv].c=u,bv++;
			else if(u==max({l,r,u})) c1[cv].a=l,c1[cv].b=r,c1[cv].c=u,cv++;
		}
		sort(a1,a1+av,cmp1);
		sort(b1,b1+bv,cmp2);
		sort(c1,c1+cv,cmp3);
		if(av>n/2) {
			for(int i=0;i<n/2;i++) sum+=a1[i].a;
			for(int i=n/2;i<av;i++) sum+=max(a1[i].b,a1[i].c);
			for(int i=0;i<bv;i++) sum+=b1[i].b;
			for(int i=0;i<cv;i++) sum+=c1[i].c;	
		}else if(bv>n/2) {
			for(int i=0;i<n/2;i++) sum+=b1[i].b;
			for(int i=n/2;i<bv;i++) sum+=max(b1[i].a,b1[i].c);
			for(int i=0;i<av;i++) sum+=a1[i].a;
			for(int i=0;i<cv;i++) sum+=c1[i].c;	
		}else if(cv>n/2) {
			for(int i=0;i<n/2;i++) sum+=c1[i].c;
			for(int i=n/2;i<cv;i++) sum+=max(c1[i].a,c1[i].b);
			for(int i=0;i<av;i++) sum+=a1[i].a;
			for(int i=0;i<bv;i++) sum+=b1[i].b;	
		}
		cout<<sum<<"\n";
	}*/
	return 0;
} 
