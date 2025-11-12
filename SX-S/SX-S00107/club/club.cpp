#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
	int d2,d3,ch2,ch3;
};
bool cmp(node n,node m){
	if(n.ch2!=m.ch2) return n.ch2>m.ch2;
	else return n.ch3>=m.ch3;
	
}
node a[100005],b[100005],c[100005],t;
int T,n,s1,s2,s3;
long long sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>t.x>>t.y>>t.z;
			if(max(t.x,max(t.y,t.z))==t.x){
				s1++;
				a[s1].x=t.x;
				a[s1].y=t.y;
				a[s1].z=t.z;
				if(max(t.y,t.z)==t.y){
					a[s1].d2=2;
					a[s1].d3=3;
					a[s1].ch2=a[s1].x-a[s1].y;
					a[s1].ch3=a[s1].x-a[s1].z;
				}
				else{
					a[s1].d2=3;
					a[s1].d3=2;
					a[s1].ch2=a[s1].x-a[s1].z;
					a[s1].ch3=a[s1].x-a[s1].y;
				}
			}
			else if(max(t.x,max(t.y,t.z))==t.y){
				s2++;
				b[s2].x=t.x;
				b[s2].y=t.y;
				b[s2].z=t.z;
				if(max(t.x,t.z)==t.x){
					b[s2].d2=1;
					b[s2].d3=3;
					b[s2].ch2=b[s2].y-b[s2].x;
					b[s2].ch3=b[s1].y-a[s1].z;
				}
				else{
					b[s2].d2=3;
					b[s2].d3=1;
					b[s2].ch2=b[s2].y-b[s2].z;
					b[s2].ch3=b[s2].y-b[s2].x;
				}
			}
			else if(max(t.x,max(t.y,t.z))==t.z){
				s3++;
				c[s3].x=t.x;
				c[s3].y=t.y;
				c[s3].z=t.z;
				if(max(t.x,t.y)==t.y){
					c[s3].d2=2;
					c[s3].d3=1;
					c[s3].ch2=c[s3].z-c[s3].y;
					c[s3].ch3=c[s3].z-c[s3].x;
				}
				else{
					c[s3].d2=1;
					c[s3].d3=2;
					c[s3].ch2=c[s3].z-c[s3].x;
					c[s3].ch3=c[s3].z-c[s3].y;
				}
			}
		}
		if(s1>=n/2+1){
			sort(a+1,a+s1+1,cmp);
		}
		while(s1>=n/2+1){
			if(a[s1].d2==2){
				if(s2+1<=n/2){
					s2++;
					b[s2].y=a[s1].y;
					s1--;
				}
				else{
					s3++;
					c[s3].z=a[s1].z;
					s1--;
				}
			}
			else{
				if(s3+1<=n/2){
					s3++;
					c[s3].z=a[s1].z;
					s1--;
				}
				else{
					s2++;
					b[s2].y=a[s1].y;
					s1--;
				}
			}
		}
		if(s2>=n/2+1){
			sort(b+1,b+s2+1,cmp);
		}
		while(s2>=n/2+1){
			if(b[s2].d2==1){
				if(s1+1<=n/2){
					s1++;
					a[s1].x=b[s2].x;
					s2--;
				}
				else{
					s3++;
					c[s3].z=b[s2].z;
					s2--;
				}
			}
			else{
				if(s3+1<=n/2){
					s3++;
					c[s3].z=b[s2].z;
					s2--;
				}
				else{
					s1++;
					a[s1].x=b[s2].x;
					s2--;
				}
			}
		}
		if(s3>=n/2+1){
			sort(c+1,c+s3+1,cmp);
		}
		while(s3>=n/2+1){
			if(c[s3].d2==2){
				if(s2+1<=n/2){
					s2++;
					b[s2].y=c[s3].y;
					s3--;
				}
				else{
					s1++;
					a[s1].x=c[s3].x;
					s3--;
				}
			}
			else{
				if(s1+1<=n/2){
					s1++;
					a[s1].x=c[s3].x;
					s3--;
				}
				else{
					s2++;
					b[s2].y=c[s3].y;
					s3--;
				}
			}
		}
		for(int i=1;i<=s1;i++){
			sum+=a[i].x;
			a[i].x=a[i].y=a[i].z=a[i].d2=a[i].d3=a[i].ch2=a[i].ch3=0;
		}
		for(int i=1;i<=s2;i++){
			sum+=b[i].y;
			b[i].x=b[i].y=b[i].z=b[i].d2=b[i].d3=b[i].ch2=b[i].ch3=0;
		}
		for(int i=1;i<=s3;i++){
			sum+=c[i].z;
			c[i].x=c[i].y=c[i].z=c[i].d2=c[i].d3=c[i].ch2=c[i].ch3=0;
		}
		cout<<sum<<"\n";
		s1=s2=s3=sum=0;
	}
	
	
	
	return 0;
}
