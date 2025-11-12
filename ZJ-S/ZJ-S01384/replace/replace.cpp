#include<bits/stdc++.h>
using namespace std;
struct st{
	long long x,y,z,xy,yz,xz,xyz,h;
}a[100005];
long long s,c,d,e;
int cmp1(st q,st w){
	return min(q.xy,min(q.yz,q.xz))<min(w.xy,min(w.yz,w.xz));
}
int cmp2(st q,st w){
	return q.yz<w.yz;
}
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long t;
	cin>>t;
	while(t--){
		int n,p;
		//memset(a,0,sizeof(0));
		s=0;c=d=e=0;
		cin>>n;
		p=n/2;
		for(long long i=0;i<n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			int ma=max(a[i].x,max(a[i].y,a[i].z));
			s=s+ma;
			a[i].xy=abs(a[i].x-a[i].y);
			a[i].xz=abs(a[i].x-a[i].z);
			a[i].yz=abs(a[i].y-a[i].z);
			a[i].h=i;
			if(ma==a[i].x){	
				a[i].xyz=1;
				a[i].yz=1e10;
				c++;
			}
			if(ma==a[i].y){
				a[i].xyz=2;
				a[i].xz=1e10;
				d++;
			}
			if(ma==a[i].z){
				a[i].xyz=3;
				a[i].xy=1e10;		
				e++;
			}
		}
		//cout<<s<<"\n";
		sort(a,a+n,cmp1);
		if(c>p){
			for(int i=0;i<n;i++){
				if(a[i].xyz==1){
					if(a[i].xy>a[i].xz){
						s=s-a[i].xz;
						c--;
						e++;
					}else{
						s=s-a[i].xy;
						c--;
						d++;
					}
				}
				if(c<=p){
					break;
				}							
			}
		}
		if(d>p){
			for(int i=0;i<n;i++){
				if(a[i].xyz==2){
					if(a[i].xy>a[i].yz){
						s=s-a[i].yz;
						d--;
						e++;
					}else{
						s=s-a[i].xy;
						d--;
						c++;
					}
				}
				if(d<=p){
					break;
				}							
			}	
		}
		if(e>p){
			for(int i=0;i<n;i++){
				if(a[i].xyz==3){
					if(a[i].xz>a[i].yz){
						s=s-a[i].yz;
						e--;
						d++;
					}else{
						s=s-a[i].xz;
						e--;
						c++;
					}
				}
				if(e<=p){
					break;
				}							
			}
		}
		cout<<s<<"\n";
	}
	return 0;
}
