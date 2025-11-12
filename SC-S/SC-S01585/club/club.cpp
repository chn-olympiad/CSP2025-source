#include<bits/stdc++.h>
using namespace std;

int t,n;
struct students{
	int x=0,y=0,z=0;
	bool flag=0;
	int p;
} a[100010],b[100010],c[100010];

bool compare1(students m,students n){
	if(m.x>n.x){
		return 0;
	}
	return 1;
}
bool compare2(students m,students n){
	if(m.y>n.y){
		return 0;
	}
	return 1;
}
bool compare3(students m,students n){
	if(m.z>n.z){
		return 0;
	}
	return 1;
}

int main(void){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		
		for(int i=0;i<=100009;i++){
			a[i].x=0,a[i].y=0,a[i].z=0;
			a[i].flag=0;
			a[i].p=i;
			b[i].x=0,b[i].y=0,b[i].z=0;
			b[i].flag=0;
			b[i].p=i;
			c[i].x=0,c[i].y=0,c[i].z=0;
			c[i].flag=0;
			c[i].p=i;
		}
		cin>>n;
		int i;
		for(i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			b[i].x=c[i].x=a[i].x;
			b[i].y=c[i].y=a[i].y;
			b[i].z=c[i].z=a[i].z;
		}
		sort(a+1,a+n+1,compare1);
		sort(b+1,b+n+1,compare2);
		sort(c+1,c+n+1,compare3);
		long long sum=0;
		for(i=1;i<=n/2;i++){
			sum+=max(a[i].x,max(b[a[i].p].y,c[a[i].p].z));
		}
		cout<<sum<<'\n';
	}
	
	return 0;
}