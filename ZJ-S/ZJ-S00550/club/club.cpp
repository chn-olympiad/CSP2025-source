#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+7;
int Max(int a,int b,int c){
	return max(a,max(b,c));
}
int t,n;
int an,bn,cn;
struct hd1{
	int max1;int max2;int max3;
}a[N],b[N],c[N];
bool cmp1(hd1 x,hd1 y){
	return x.max1+y.max2>x.max2+y.max1;
}
bool cmp2(hd1 x,hd1 y){
	return x.max1>y.max1;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int t1=1;t1<=t;t1++){
		cin>>n;
		an=0;bn=0;cn=0;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			if(Max(x,y,z)==x){
				a[++an].max1=x;
				a[an].max2=max(y,z);
				a[an].max3=min(y,z); 
			}else if(Max(x,y,z)==y){
				b[++bn].max1=y;
				b[bn].max2=max(x,z);
				b[bn].max3=min(x,z); 
			}else{
				c[++cn].max1=z;
				c[cn].max2=max(y,x);
				c[cn].max3=min(y,x); 
			}
		}
		int ans=0;
		if(an<=n/2){
			sort(a+1,a+1+an,cmp2);
			for(int i=1;i<=an;i++)ans+=a[i].max1;
		}else{
			sort(a+1,a+1+an,cmp1);
			for(int i=1;i<=an;i++){
				if(i<=n/2)ans+=a[i].max1;
				else ans+=a[i].max2;
			}
		}
		if(bn<=n/2){
			sort(b+1,b+1+bn,cmp2);
			for(int i=1;i<=bn;i++)ans+=b[i].max1;
		}else{
			sort(b+1,b+1+bn,cmp1);
			for(int i=1;i<=bn;i++){
				if(i<=n/2)ans+=b[i].max1;
				else ans+=b[i].max2;
			}
		}
		if(cn<=n/2){
			sort(c+1,c+1+cn,cmp2);
			for(int i=1;i<=cn;i++)ans+=c[i].max1;
		}else{
			sort(c+1,c+1+cn,cmp1);
			for(int i=1;i<=cn;i++){
				if(i<=n/2)ans+=c[i].max1;
				else ans+=c[i].max2;
			}
		}cout<<ans<<"\n";
	}
	return 0;
}
