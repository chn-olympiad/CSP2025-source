#include<bits/stdc++.h> 
using namespace std;
const int N=1e5+7;
int t,n,s,p=0,q=0,c=0,d=0;
struct stu{
	int x,y,z;
}v[N];
int m[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);s=n/2; 
		int ans=0,q=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&v[i].x,&v[i].y,&v[i].z);
			if(v[i].y==v[i].z&&v[i].z==0) q++;
			ans+=max((v[i].x,v[i].y),v[i].z);
		}
		if(q==n) cout<<s<<"\n";
		else if(n==n){
			if(v[1].x>v[1].y&&v[1].y>v[1].z) p=v[1].x,q=1;
			if(v[1].y>v[1].x&&v[1].x>v[1].z) p=v[1].y,q=2;
			if(v[1].z>v[1].x&&v[1].x>v[1].y) p=v[1].z,q=3;
			
			if(v[2].x>v[2].y&&v[2].y>v[2].z) c=v[1].x,d=1;
			if(v[2].y>v[2].x&&v[2].x>v[2].z) c=v[1].y,d=2;
			if(v[2].z>v[2].x&&v[2].x>v[2].y) c=v[1].z,d=3;
			if(p!=c) cout<<p+c<<"\n";
			else cout<<p+v[1].y<<"\n";
		}
	}
	return 0;
}
