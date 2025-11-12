#include<bits/stdc++.h>
using namespace std;
int a,b,s,m[3];
struct node{
	int x,y,z,u,v,w;
};
node n[200010];
bool cmp(node c,node d){
	return c.w<d.w;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>a;
	while(a--){
		cin>>b;
		s=0;
		m[0]=m[1]=m[2]=0;
		for(int i=0;i<b;i++){
			cin>>n[i].x>>n[i].y>>n[i].z;
			if(n[i].x>=n[i].y and n[i].x>=n[i].z){
				n[i].u=0;
				if(n[i].y>=n[i].z){
					n[i].v=1;
					n[i].w=n[i].x-n[i].y;
				}
				else{
					n[i].v=2;
					n[i].w=n[i].x-n[i].z;
				}
				s+=n[i].x;
			}
			else if(n[i].y>=n[i].x and n[i].y>=n[i].z){
				n[i].u=1;
				if(n[i].x>=n[i].z){
					n[i].v=0;
					n[i].w=n[i].y-n[i].x;
				}
				else{
					n[i].v=2;
					n[i].w=n[i].y-n[i].z;
				}
				s+=n[i].y;
			}
			else{
				n[i].u=2;
				if(n[i].x>=n[i].y){
					n[i].v=0;
					n[i].w=n[i].z-n[i].x;
				}
				else{
					n[i].v=1;
					n[i].w=n[i].z-n[i].y;
				}
				s+=n[i].z;
			}
			m[n[i].u]++;
		}
		sort(n+0,n+b,cmp);
		int xx=0;
		for(int i=0;i<b;i++){
			if(m[n[i].u]>b/2){
				m[n[i].u]--;
				s-=n[i].w;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
