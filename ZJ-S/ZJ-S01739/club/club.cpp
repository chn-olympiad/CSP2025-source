#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z,id;
}a[100005],b[100005];
bool cmp1(node p,node q){
	int xx=p.x-max(p.y,p.z),yy=q.x-max(q.y,q.z);
	return xx>yy;
}
bool cmp2(node p,node q){
	int xx=p.y-max(p.x,p.z),yy=q.y-max(q.x,q.z);
	return xx>yy;
}
bool cmp3(node p,node q){
	int xx=p.z-max(p.y,p.x),yy=q.z-max(q.y,q.x);
	return xx>yy;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a1=0,a2=0,a3=0,tot=0;	
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].id=i;
			if(a[i].x>a[i].y&&a[i].x>a[i].z) a1++;
			else if(a[i].y>a[i].x&&a[i].y>a[i].z) a2++;
			else if(a[i].z>a[i].x&&a[i].z>a[i].y) a3++;
		}
		long long sum=0;
		for(int i=1;i<=n;i++) sum+=max(a[i].x,max(a[i].y,a[i].z));
		if(max(a1,max(a2,a3))*2<=n) cout<<sum<<'\n';
		else{
			if(a1*2>n){
				for(int i=1;i<=n;i++){
					if(a[i].x>a[i].y&&a[i].x>a[i].z){
						tot++;
						b[tot]=a[i];
					}
				}
				sort(b+1,b+tot+1,cmp1);
				for(int i=tot;i>n/2;i--){
					int j=b[i].id;
					sum-=(a[j].x-max(a[j].y,a[j].z));
				}
			}
			else if(a2*2>n){
				for(int i=1;i<=n;i++){
					if(a[i].y>a[i].x&&a[i].y>a[i].z){
						tot++;
						b[tot]=a[i];
					}
				}
				sort(b+1,b+tot+1,cmp2);
				for(int i=tot;i>n/2;i--){
					int j=b[i].id;
					sum-=(a[j].y-max(a[j].x,a[j].z));
				}
			}
			else{
				for(int i=1;i<=n;i++){
					if(a[i].z>a[i].x&&a[i].z>a[i].y){
						tot++;
						b[tot]=a[i];
					}
				}
				sort(b+1,b+tot+1,cmp3);
				for(int i=tot;i>n/2;i--){
					int j=b[i].id;
					sum-=(a[j].z-max(a[j].y,a[j].x));
				}
			}
			cout<<sum<<'\n';
		}
	}
	return 0;
}
