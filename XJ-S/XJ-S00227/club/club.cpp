#include<bits/stdc++.h>
using namespace std;
int t;
struct node{
	int x,y,a,b;
}a[100100];
bool cmp(node x,node y){
	if(x.x-x.y==y.x-y.y){
		return x.x>y.x;
	}else{
		return x.x-x.y>y.x-y.y; 
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
    	int n,ans=0;
    	cin>>n;
        for(int i=1;i<=n;i++){
        	int x,y,z;
        	cin>>x>>y>>z;
        	a[i].x=max(max(x,y),z);
        	int k=min(min(x,y),z);
        	if(x==k){
        		if(a[i].x==y){
        			a[i].y=z;
        			a[i].b=3;
        			a[i].a=2;
				}else{
					a[i].y=y;
					a[i].b=2;
        			a[i].a=3;
				}
			}else if(y==k){
				if(a[i].x==x){
        			a[i].y=z;
        			a[i].b=3;
        			a[i].a=1;
				}else{
					a[i].y=x;
					a[i].b=1;
        			a[i].a=3;
				}
			}else{
				if(a[i].x==y){
        			a[i].y=x;
        			a[i].b=1;
        			a[i].a=2;
				}else{
					a[i].y=y;
					a[i].b=2;
        			a[i].a=1;
				}
			}
		}
		sort(a+1,a+1+n,cmp);
		int d[4];
		for(int i=0;i<=3;i++){
			d[i]=0;
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			if(d[a[i].a]<n/2){
				d[a[i].a]++;
				sum+=a[i].x;
			}else{
				d[a[i].b]++;
				sum+=a[i].y ;
			}
			
		}
		 cout<<sum<<endl;
	}

	return 0;
}

