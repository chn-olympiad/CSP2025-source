#include <bits/stdc++.h>
using namespace std;
int n,m,x[1000001],y[1000001],z[1000001],t,sum;
struct node{
	int a;
	int b;
	int c;
}q[1000000];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			x[i]=0;
			y[i]=0;
			z[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>q[i].a>>q[i].b>>q[i].c;
			if(q[i].a>q[i].b&&q[i].a>q[i].c) x[i]=q[i].a;
			else if(q[i].b>q[i].a&&q[i].b>q[i].c) y[i]=q[i].b;
			else if(q[i].c>q[i].a&&q[i].c>q[i].b) z[i]=q[i].c;
		}
		sort(x+1,x+1+n,cmp);
		sort(y+1,y+1+n,cmp);
		sort(z+1,z+1+n,cmp);
		for(int i=1;i<=n/2;i++){
			sum+=x[i]+y[i]+z[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}
