#include<bits/stdc++.h>
using namespace std;
int t,n;
struct cluber{
	int a,b,c;
	bool operator<(const cluber tmp)const{
	       return tmp.a<a;
	}
}a[100005];
int q[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		bool io=0;
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
		   cin>>a[i].a>>a[i].b>>a[i].c; 
		   q[i]=max(a[i].a,max(a[i].b,a[i].c));
		   if(a[i].b!=0||a[i].c!=0){
		   	  io=1;
		   } 
	    }	
	    sort(a+1,a+1+n);
	    if(io==1){
	    for(int i=1;i<=n/2;i++){
	    	ans+=a[i].a;
		}
		}
	    else{
          for(int i=1;i<=n;i++){
          	ans+=q[i];
		  }
    }
		cout<<ans;
	}
	return 0;
}
