#include<bits/stdc++.h>
using namespace std;
int t,n,l;
struct stu{
	int x,xx,y,yg,z,zz;
}a[100005];
bool cmp(stu x,stu y){
	if(x.z>y.z) return 1;
	else if(x.z==y.z&&x.y>y.y) return 1;
	else if(x.z==y.z&&x.y==y.y&&x.z>y.z) return 1;
	else return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		int h=0,c[4]={0,0,0,0};
		for(int j=0;j<n;j++){
			cin>>a[j].x>>a[j].y>>a[j].z;
			a[j].xx=1,a[j].yg=2,a[j].zz=3;
			if(a[j].x>a[j].y){
				swap(a[j].x,a[j].y);swap(a[j].xx,a[j].yg);
			}
			if(a[j].y>a[j].z){
				swap(a[j].y,a[j].z);swap(a[j].yg,a[j].zz);
			}
			if(a[j].x>a[j].y){
				swap(a[j].x,a[j].y);swap(a[j].xx,a[j].yg);
			}
		}
		sort(a,a+n,cmp);
		reverse(a,a+n);
		for(int j=0;j<n;j++){
			c[a[j].zz]++;
			if(c[a[j].zz]>n/2){
				c[a[j].yg]++;
				c[a[i].zz]--; 
				h+=a[j].y;
			}else h+=a[j].z;
		}
		cout<<h<<endl;
	}
	return 0;
}
