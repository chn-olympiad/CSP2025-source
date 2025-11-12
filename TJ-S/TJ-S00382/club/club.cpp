#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct node{
	int v[5];
	int x,y,z;
	int c1,c2;
}m[100005];
node a[100005],b[100005],c[100005];
long long ans;
int t1,t2,t3;
bool cmp(node a,node b){
	return a.c1<b.c1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>m[i].v[1]>>m[i].v[2]>>m[i].v[3];
			m[i].x=max(m[i].v[1],max(m[i].v[2],m[i].v[3]));
			m[i].z=min(m[i].v[1],min(m[i].v[2],m[i].v[3]));
			m[i].y=m[i].v[1]+m[i].v[2]+m[i].v[3]-m[i].x-m[i].z;
			m[i].c1=m[i].x-m[i].y;
			m[i].c2=m[i].y-m[i].z;
			if(m[i].x==m[i].v[1])m[i].x=1;
			else if(m[i].x==m[i].v[2])m[i].x=2;
			else if(m[i].x==m[i].v[3])m[i].x=3;
			if(m[i].y==m[i].v[1])m[i].y=1;
			else if(m[i].y==m[i].v[2])m[i].y=2;
			else if(m[i].y==m[i].v[3])m[i].y=3;
			if(m[i].z==m[i].v[1])m[i].z=1;
			else if(m[i].z==m[i].v[2])m[i].z=2;
			else if(m[i].z==m[i].v[3])m[i].z=3;
		}
		for(int i=1;i<=n;i++){
			ans+=m[i].v[m[i].x];
			if(m[i].x==1)a[++t1]=m[i];
			else if(m[i].x==2)b[++t2]=m[i];
			else if(m[i].x==3)c[++t3]=m[i];
		}
		if(t1>n/2){
			sort(a+1,a+1+t1,cmp);
			for(int i=1;i<=t1-n/2;i++){
				ans-=a[i].c1;
				a[i].c1=a[i].c2;
				if(a[i].y==2)b[++t2]=a[i];
				if(a[i].y==3)c[++t3]=a[i];
			}
		}else if(t2>n/2){
			sort(b+1,b+1+t2,cmp);
			for(int i=1;i<=t2-n/2;i++){
				ans-=b[i].c1;
				b[i].c1=b[i].c2;
				if(b[i].y==1)a[++t1]=b[i];
				if(b[i].y==3)c[++t3]=b[i];
			}
		}else if(t3>n/2){
			sort(c+1,c+1+t3,cmp);
			for(int i=1;i<=t3-n/2;i++){
				ans-=c[i].c1;
				c[i].c1=c[i].c2;
				if(c[i].y==2)b[++t2]=c[i];
				if(c[i].y==1)a[++t1]=c[i];
			}
		}if(t1>n/2){
			sort(a+1,a+1+t1,cmp);
			for(int i=1;i<=t1-n/2;i++){
				ans-=a[i].c1;
				if(a[i].y==2)b[++t2]=a[i];
				if(a[i].y==3)c[++t3]=a[i];
			}
		}else if(t2>n/2){
			sort(b+1,b+1+t2,cmp);
			for(int i=1;i<=t2-n/2;i++){
				ans-=b[i].c1;
				if(b[i].y==1)a[++t1]=b[i];
				if(b[i].y==3)c[++t3]=b[i];
			}
		}else if(t3>n/2){
			sort(c+1,c+1+t3,cmp);
			for(int i=1;i<=t3-n/2;i++){
				ans-=c[i].c1;
				if(c[i].y==2)b[++t2]=c[i];
				if(c[i].y==1)a[++t1]=c[i];
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
