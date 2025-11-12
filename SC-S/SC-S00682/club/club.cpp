#include<bits/stdc++.h> 
using namespace std;
long long x,y,z,n,t,cnt,a[200005],b[200005],c[200005],d[200005],aa,bb,cc,e[200005],f[200005];
int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>t;
	while(t!=0){
		cin>>n;
		for(int i=1;i<=n;i++){
				cin>>a[i]>>b[i]>>c[i];
				if(a[i]>=b[i]&&a[i]>=c[i]){
					aa++;
					cnt+=a[i];
					d[aa]=min(a[i]-b[i],a[i]-c[i]);
				}
				else if(b[i]>=a[i]&&b[i]>=c[i]){
					bb++;
					cnt+=b[i];
					e[bb]=min(b[i]-c[i],b[i]-a[i]);
				}
				else if(c[i]>=a[i]&&c[i]>=b[i]){
					cc++;
					cnt+=c[i];
					f[cc]=min(c[i]-b[i],c[i]-a[i]);
				}
			}
		if(aa<=n/2&&bb<=n/2&&cc<=n/2){
			cout<<cnt<<endl;
		}
		else if(aa>n/2){
			x=aa-n/2;
			sort(d+1,d+aa+1);
			for(int i=1;i<=x;i++){
				cnt-=d[i];
			}
			cout<<cnt<<endl; 
		}
		else if(bb>n/2){
			y=bb-n/2;
			sort(e+1,e+bb+1);
			for(int i=1;i<=y;i++){
				cnt-=e[i];
			}
			cout<<cnt<<endl;
		}
		else if(cc>n/2){
			z=cc-n/2;
			sort(f+1,f+cc+1);
			for(int i=1;i<=z;i++){
				cnt-=f[i];
			}
			cout<<cnt<<endl;
		}
		cnt=0;
		aa=0;bb=0;cc=0;n=0;x=0,y=0,z=0;
		for(int i=1;i<=200000;i++){
		a[i]=0;b[i]=0;c[i]=0;d[i]=0;e[i]=0;f[i]=0;
		}
		t--;	 
	}	
	return 0;
}