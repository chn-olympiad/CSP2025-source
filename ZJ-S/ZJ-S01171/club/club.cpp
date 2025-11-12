#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	int b;
	int c;
}a[100010];
struct zj{
	int x;
	int y;
	char z;
}b[100010];
struct hz{ 
	int x;
	int y;
	char z;
}c[100010];
struct hsd{
	int x;
	int y;
	char z;
}d[100010];
bool ck(zj a,zj b){
	return a.y>b.y;
}
bool cc(hz a,hz b){
	return a.y>b.y;
}
bool cg(hsd a,hsd b){
	return a.y>b.y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ak=0,ac=0,ag=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
				b[++ak].x=i;
				if(a[i].a-a[i].b<=a[i].a-a[i].c){
					b[ak].y=a[i].a-a[i].b;
					b[ak].z='b';
				}else{
					b[ak].y=a[i].a-a[i].c;
					b[ak].z='c';
				}
			}
			else if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
				c[++ac].x=i;
				if(a[i].b-a[i].a<=a[i].b-a[i].c){
					c[ac].y=a[i].b-a[i].a;
					c[ac].z='a';
				}else{
					c[ac].y=a[i].b-a[i].c;
					c[ac].z='c';
				}
			}
			else if(a[i].c>=a[i].b&&a[i].c>=a[i].a){
				d[++ag].x=i;
				if(a[i].c-a[i].b<=a[i].c-a[i].a){
					d[ag].y=a[i].c-a[i].b;
					d[ag].z='b';
				}else{
					d[ag].y=a[i].c-a[i].a;
					d[ag].z='a';
				}
			}
		}
		sort(b+1,b+ak+1,ck);
		sort(c+1,c+ac+1,cc);
		sort(d+1,d+ag+1,cg);
		if(ak>n/2){
			for(int i=n/2+1;i<=ak;i++){
				int p=b[i].x;
				if(ac<n/2&&b[i].z=='b'){
					c[++ac].x=b[i].x;
					c[ac].y=a[p].a+b[i].y;
					c[ac].z=b[i].z;
				}else{
					d[++ag].x=b[i].x;
					d[ag].y=a[p].a+b[i].y;
					d[ag].z=b[i].z;
				}
			}
			ak=n/2;
		}
		else if(ac>n/2){
			for(int i=n/2+1;i<=ac;i++){
				int p=c[i].x;
				if(ak<n/2&&c[i].z=='a'){
					b[++ak].x=c[i].x;
					b[ak].y=a[p].b+c[i].y;
					b[ak].z=c[i].z;
				}else{
					d[++ag].x=c[i].x;
					d[ag].y=a[p].b+c[i].y;
					d[ag].z=c[i].z;
				}
			}
			ac=n/2;
		}
		else if(ag>n/2){
			for(int i=n/2+1;i<=ag;i++){
				int p=d[i].x;
				if(ak<n/2&&d[i].z=='a'){
					b[++ak].x=d[i].x;
					b[ak].y=a[p].c+d[i].y;
					b[ak].z=d[i].z;
				}else{
					c[++ac].x=d[i].x;
					c[ac].y=a[p].c+d[i].y;
					c[ac].z=d[i].z;
				}
			}
			ag=n/2;
		}
		long long ans=0;
		for(int i=1;i<=ak;i++){
			int p=b[i].x;
			ans+=a[p].a;
		}
		for(int i=1;i<=ac;i++){
			int p=c[i].x;
			ans+=a[p].b;
		}
		for(int i=1;i<=ag;i++){
			int p=d[i].x;
			ans+=a[p].c;
		}
		cout<<ans<<endl;
	}
	return 0;
}
