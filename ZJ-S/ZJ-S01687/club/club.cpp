#include<bits/stdc++.h>
using namespace std;
struct peo{
	int x,id;
};
int t,n;
peo a[100100],b[100100],c[100100];
//int aa[100100],bb[100100],cc[100100];
int s,sa,sb,sc,pa=1,pb=1,pc=1;
bool f[100100];
bool cmp(peo x,peo y){
	return x.x>y.x;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int h=1;h<=t;h++){
		memset(a,0,sizeof(a));memset(b,0,sizeof(b));memset(c,0,sizeof(c));
		memset(f,0,sizeof(f));s=0;sa=sb=sc=0;pa=pb=pc=1;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i].x>>b[i].x>>c[i].x,a[i].id=b[i].id=c[i].id=i;
		sort(a+1,a+n+1,cmp);sort(b+1,b+n+1,cmp);sort(c+1,c+n+1,cmp);
		while((sa+pa)<n&&(sb+pb)<n&&(sc+pc)<n){
			while(f[a[sa+pa].id])pa++;
			if(sa<(n/2)&&(sb>=n/2||a[sa+pa].x>=b[sb+pb].x)&&(sc>=n/2||a[sa+pa].x>=c[sc+pc].x)){
				s+=a[sa+pa].x,f[a[sa+pa].id]=1,sa++;
			}
			while(f[b[sb+pb].id])pb++;
			if(sb<(n/2)&&(sa>=n/2||b[sb+pb].x>=a[sa+pa].x)&&(sc>=n/2||b[sb+pb].x>=c[sc+pc].x)){
				s+=b[sb+pb].x,f[b[sb+pb].id]=1,sb++;
			}
			while(f[c[sc+pc].id])pc++;
			if(sc<(n/2)&&(sa>=n/2||c[sc+pc].x>=a[sa+pa].x)&&(sb>=n/2||c[sc+pc].x>=b[sb+pb].x)){
				s+=c[sb+pb].x,f[c[sc+pc].id]=1,sc++;
			}
		}
		cout<<s<<"\n";
	}
	return 0;
}

