#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
};
node a[100005],b[100005],c[100005];
bool cmp1(node x,node y){
	return x.x-max(x.y,x.z)>y.x-max(y.y,y.z);
}
bool cmp2(node x,node y){
	return x.y-max(x.x,x.z)>y.y-max(y.x,y.z);
}
bool cmp3(node x,node y){
	return x.z-max(x.x,x.y)>y.z-max(y.x,y.y);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ind1=0,ind2=0,ind3=0;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			int mx=max({x,y,z});
			if(mx==x){
				a[++ind1]=(node){x,y,z};
			}
			else if(mx==y){
				b[++ind2]=(node){x,y,z};
			}
			else{
				c[++ind3]=(node){x,y,z};
			}
		}
		if(ind1>n/2){
			sort(a+1,a+ind1+1,cmp1);
			int tmp=ind1;
			for(int i=tmp;i>n/2;i--){
				if(a[i].y>a[i].z){
					b[++ind2]=a[i];
				}
				else{
					c[++ind3]=a[i];
				}
				a[ind1]={0,0,0};
				ind1--;
			}
		}
		else if(ind2>n/2){
			sort(b+1,b+ind2+1,cmp2);
			int tmp=ind2;
			for(int i=tmp;i>n/2;i--){
				if(b[i].x>b[i].z){
					a[++ind1]=b[i];
				}
				else{
					c[++ind3]=b[i];
				}
				b[ind2]={0,0,0};
				ind2--;
			}
		}
		else if(ind3>n/2){
			sort(c+1,c+ind3+1,cmp3);
			int tmp=ind3;
			for(int i=tmp;i>n/2;i--){
				if(c[i].x>c[i].y){
					a[++ind1]=c[i];
				}
				else{
					b[++ind2]=c[i];
				}
				c[ind3]={0,0,0};
				ind3--;
			}
		}
		int ans=0;
		for(int i=1;i<=ind1;i++){
			ans+=a[i].x;
			a[i]={0,0,0};
		}
		for(int i=1;i<=ind2;i++){
			ans+=b[i].y;
			b[i]={0,0,0};
		}
		for(int i=1;i<=ind3;i++){
			ans+=c[i].z;
			c[i]={0,0,0};
		}
		cout<<ans<<"\n";
	}
	return 0;
}
