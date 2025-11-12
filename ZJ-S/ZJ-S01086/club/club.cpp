#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x,y,z,u,v,w;
}a[100010];
long long T,n,maxs,sum,b[5];
bool cmp(node i,node j){
	return(i.x-i.y>j.x-j.y||(i.x-i.y==j.x-j.y&&i.y-i.z>j.y-j.z)||(i.x-i.y==j.x-j.y&&i.y-i.z==j.y-j.z&&i.x>j.x));
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		sum=0;
		b[1]=b[2]=b[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].u=1,a[i].v=2,a[i].w=3;
			if(a[i].x<a[i].y) swap(a[i].x,a[i].y),swap(a[i].u,a[i].v);
			if(a[i].x<a[i].z) swap(a[i].x,a[i].z),swap(a[i].u,a[i].w);
			if(a[i].y<a[i].z) swap(a[i].y,a[i].z),swap(a[i].v,a[i].w);
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(b[a[i].u]==n/2){
				b[a[i].v]++;
				sum+=a[i].y;
			}
			else{
				b[a[i].u]++;
				sum+=a[i].x;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}