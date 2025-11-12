#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;
struct Node{
	int x,y,z;
}a[N];

int t,n;
bool f1,f2;
bool cmp(Node a,Node b){
	if(a.x>b.x){
		return a.x>b.x;
	}else{
		return a.x<b.x;
	}
}
int main(){
	//freopen("club1.in","r",stdin);
	//freopen("club1.out","w",stdout);
	cin>>t;
	while(t--){
        cin>>n;
        if(n==2){
       	int b[4];
       	    int maxn=-1e9+1,maxn2=-1e9+1,maxn3=-1e9+3;
       	    for(int i=1;i<=n;i++){
       	  	    cin>>a[i].x>>a[i].y>>a[i].z;
       	  	    b[1]=max(maxn,a[i].x);
       	  	    b[2]=max(maxn2,a[i].y);
       	  	    b[3]=max(maxn3,a[i].z);
			}
			sort(b+1,b+3);
			int ans=b[2]+b[3];
			cout<<ans<<endl;
	    }else if(n>2){
	    for(int i=1;i<=n;i++){
       	  	for(int i=1;i<=n;i++){
       	  	    cin>>a[i].x>>a[i].y>>a[i].z;
       	  	    if(a[i].y!=0){
       	  	    	f1=true;
				}
				if(a[i].z!=0){
					f2=true;
				}
			}
			if(!f1){
				if(!f2){
					sort(a+1,a+n+1,cmp);
					cout<<a[1].x;
					cout<<a[2].x;
				}
			}	
		
       	  	    
       	  	    
		}
	}
}
	return 0;
}
