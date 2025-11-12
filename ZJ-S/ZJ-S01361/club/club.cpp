#include<bits/stdc++.h>
using namespace std;
int t,n,b[4],s,l,fl,c[1000001],d[1000001],x;
struct kkk{
	int bh,p;
}a[1000001][4];
void f(){
	for(int i=1;i<=n;i++){
		if(a[i][1].bh==fl)c[a[i][1].p-a[i][2].p]=1,d[i]=a[i][2].bh;
	}
	for(int i=1;i<=20000&&x>=1;i++){
		if(c[i]>=0) s-=i,x--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		s=0;
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i][1].p);
			scanf("%d",&a[i][2].p);
			scanf("%d",&a[i][3].p);
			a[i][1].bh=1,a[i][2].bh=2,a[i][3].bh=3;
			if(a[i][1].p<a[i][2].p) swap(a[i][1],a[i][2]);
			if(a[i][1].p<a[i][3].p) swap(a[i][1],a[i][3]);
			if(a[i][2].p<a[i][3].p) swap(a[i][2],a[i][3]);
			b[a[i][1].bh]++;
			s+=a[i][1].p;
		}
		for(int i=1;i<=3;i++){
			if(b[i]>n/2){
				fl=i;
				x=b[i]-n/2;
				f();
			} 
		}
		cout<<s<<endl;
	}
	return 0;
}
