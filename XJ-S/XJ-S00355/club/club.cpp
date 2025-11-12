#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,da[N],ans;

struct rode{ 
int x;int y;int z;
	}b[N];
	
struct code{ 
int x;int y;int z;
	}ren[N];	

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int zu=1;zu<=t;zu++){
			cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i].x>>b[i].y>>b[i].z;
	}
	for(int i=1;i<=n;i++){
		if(b[i].x>=b[i].y&&b[i].x>=b[i].z ){
			da[i]=b[i].x ;
			ren[n].x++;
		}
		if(b[i].y>=b[i].x&&b[i].y>=b[i].z ){
			da[i]=b[i].y ;
			ren[n].y++;
		}
		if(b[i].z>=b[i].x&&b[i].z>=b[i].y ){
			da[i]=b[i].z ;
			ren[n].z++;
		}
		ans=ans+da[i];
	}
	
	
	cout<<ans<<endl;
	ans=0;
	}
	return 0;
}

