#include<bits/stdc++.h>
using namespace std;
long long t,n,s=0,sum=0,xx=0,yy=0,zz=0;
struct o{
	long long x,y,z;
}a[200005];
long long maxx(long long x,long long y,long long z){
	 if(x>y){
		if(x>z) return 1;
		else return 3;	
	}
	 else{
	  if(y>z) return 2;
	  else return 3;	
	}
}
long long maxxx(long long x,long long y){
	if(x>y) return 1;
	else return 2;
}
int cmp(o a,o b){
	if(a.x==b.x){
		if(a.y==b.y){
			return a.z>b.z;
		}
		else return a.y>b.y;
	}
	else return a.x>b.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		sum=0,s=0,xx=0,yy=0,zz=0;
		if(n==2){
			for(int i=1;i<=n;i++){
				cin>>a[i].x>>a[i].y>>a[i].z;
			}
          sum=max(a[1].x+a[2].y,a[1].x+a[2].z);
          sum=max(sum,a[1].y+a[2].x);
          sum=max(sum,a[1].y+a[2].z);
          sum=max(sum,a[1].z+a[2].x);
          sum=max(sum,a[1].z+a[2].y);
          cout<<sum<<endl;
		}
		else{
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
}
         sort(a+1,a+n+1,cmp);
for(int i=1;i<=n;i++){
	     s=maxx(a[i].x,a[i].y,a[i].z);
	     if(s==1){
	     	xx++;
	     if(n/2<xx){
	     	s=maxxx(a[i].y,a[i].z);
	     	if(s==1){
	     	 if(n/2==yy){
	     	   zz++;
	     	   sum+=a[i].z;
	         }
			else yy++,sum+=a[i].y;	
			 }
			 else{
			 	if(n/2==zz){
	     	   yy++;
	     	   sum+=a[i].y;
	         }
			else zz++,sum+=a[i].z;	
			  } 
			  xx--;
			 }
			 else sum+=a[i].x;
	     }	 
	    if(s==2){
	     	yy++;
	     if(n/2<yy){
	     	s=maxxx(a[i].x,a[i].z);
	     	if(s==1){
	     	 if(n/2==xx){
	     	   zz++;
	     	   sum+=a[i].z;
	         }
			else xx++,sum+=a[i].x;	
			 }
			 else{
			 	if(n/2==zz){
	     	   xx++;
	     	   sum+=a[i].x;
	         }
			else zz++,sum+=a[i].z;	
			  } 
			  yy--;
			 }
			 else sum+=a[i].y;
	     }	 
	     if(s==3){
	     	zz++;
	     if(n/2<zz){
	     	s=maxxx(a[i].y,a[i].x);
	     	if(s==1){
	     	 if(n/2==yy){
	     	   xx++;
	     	   sum+=a[i].x;
	         }
			else yy++,sum+=a[i].y;	
			 }
			 else{
			 	if(n/2==xx){
	     	   yy++;
	     	   sum+=a[i].y;
	         }
			else xx++,sum+=a[i].x;	
			  } 
			  zz--;
			 }
			 else sum+=a[i].z;
	     }	 
	}
	     cout<<sum<<endl;
		}
}
	return 0;
}
