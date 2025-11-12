#include<bits/stdc++.h>
using namespace std;
struct w{
	long long x,y,z,b;
}a[1000005];
long long b[1000005],c[1000005],d[1000005],t,f,n,x,y,z,q,ma1,ma2,ma3,num,b_1,c_1,d_1,f1,f2,f3;
string s;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
		while(t--){
		cin>>n;
		if(n==2){
			cin>>a[1].x>>a[1].y>>a[1].z;
			cin>>a[2].x>>a[2].y>>a[2].z;
			cout<<max(max(a[1].x+a[2].z,max(a[1].y+a[2].x,max(a[1].y+a[2].z,max(a[1].z+a[2].x,a[1].z+a[2].y)))),a[1].x+a[2].y)<<endl;
		}
		else{
			x=0;
			f=0;
			for(int i=1;i<=n;i++){
				cin>>a[i].x>>a[i].y>>a[i].z;
				if(a[i].y!=0||a[i].z!=0){
					f=1;
					break;	
				}
			}
			if(f){
				for(int i=1;i<=n;i++){
					a[i].b=max(a[i].x,max(a[i].y,a[i].z));
					x+=a[i].b;
				}
				cout<<x<<endl;
			}
			else{
				for(int i=1;i<=n;i++){
					b[i]=a[i].x;
				}
				sort(b+1,b+1+n);
				reverse(b+1,b+1+n);
				cout<<b[1]+b[2]<<endl;
			}
		}
		
	}


	return 0;
}
