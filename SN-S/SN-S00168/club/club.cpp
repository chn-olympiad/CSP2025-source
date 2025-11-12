//ËÎÐûµÂ SN-S00168 ¸¨ÂÖÖÐÑ§ 
#include<bits/stdc++.h>
using namespace std;
int a[100005],b,c,d,e,f[100005],g[100005],h,k,x,y,z,o,p,m;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>b>>c>>d;
			a[j]=b;
			f[j]=c;
			g[j]=d;
			b=0;
			c=0;
			d=0;
		}
		for(int i=0;i<n;i++){
			if(a[i]>=e){
				x=i;
				e=a[i];
			}
			if(a[i]>=h){
				y=i;
				h=a[i];
			}
			if(a[i]>=k){
				z=i;
				k=a[i];
			}
			if(x==y||x==z||y==z){
				if(e>h){
					h=0;
					if(e>k){
						k=0;
					}else{
						e=0;
					}
				}else{
					e=0;
					if(h>k){
						k=0;
					}else{
						h=0;
					}
				}
			}
			if(e){
				o=e;
			}
			if(h){
				p=h;
			}
			if(k){
				m=k;
			}
		}
		cout<<p+o+m<<" ";
	}
	return 0;
} 
