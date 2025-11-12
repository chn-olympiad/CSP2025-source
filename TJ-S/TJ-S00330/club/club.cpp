#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
bool f=true;
long long t,n,sum=0,ma=-1;
struct no{
	long long a1,a2,a3,s,m;
}a[N],b[N]={0};
bool cmp(no x,no y){
	return x.m>y.m;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		sum=0;
		cin>>n;
		long long v1=n/2,v2=n/2,v3=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;	
		}
		for(int i=1;i<=n;i++){
			ma=-1;
			if(ma<=a[i].a1){
				ma=a[i].a1;
				b[i].s=1;
				b[i].m=ma;
			}
			if(ma<=a[i].a2){
				ma=a[i].a2;
				b[i].s=2;
				b[i].m=ma;
			}
			if(ma<=a[i].a3){
				ma=a[i].a3;
				b[i].s=3;
				b[i].m=ma;
			}
			
		}
		sort(b+1,b+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			if(b[i].s==b[i+1].s){
				f=false;
			}
			if(b[i].s!=b[i+1].s){
				f=true;
			}
		}
		ma=-1;
		if(f==false){
			if(ma<a[1].a1&&a[1].a1!=b[1].m){
				ma=a[1].a1;
				b[1].s=1;
				b[1].m=ma;
			}
			if(ma<=a[1].a2&&a[1].a2!=b[1].m){
				ma=a[1].a2;
				b[1].s=2;
				b[1].m=ma;
			}
			if(ma<=a[1].a3&&a[1].a3!=b[1].m){
				ma=a[1].a3;
				b[1].s=3;
				b[1].m=ma;
			}
		}
		sort(b+1,b+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(v1!=0&&b[i].s==1){
				sum+=b[i].m;
				v1--;
			}else if(v2!=0&&b[i].s==2){
				sum+=b[i].m;
				v2--;
			}else if(v2!=0&&b[i].s==3){
				sum+=b[i].m;
				v3--;
			}
		}
		cout<<sum<<' ';
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
