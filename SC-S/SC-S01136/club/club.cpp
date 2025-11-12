#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
struct node{
	int x,y,z;
	bool operator < (const node &p)const{
		int a=0;
		if(p.x>x)	a++;
		if(p.y>y)	a++;
		if(p.z>z)	a++;
		if(p.x+p.y+p.z>x+y+z)	return a>1;
		else					return a<=1;
	}
}a[N];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			int x,y,z;scanf("%d%d%d",&x,&y,&z);
			a[i]={x,y,z};
		}
		int tmp=n/2;
		sort(a+1,a+1+n);
		int ans=0,cnta=0,cntb=0,cntc=0;
		for(int i=1;i<=n;i++){
			int res=0;int op=0;
			if(cnta<tmp&&res<a[i].x)	res=a[i].x,op=1;
			if(cntb<tmp&&res<a[i].y)	res=a[i].y,op=2;
			if(cntc<tmp&&res<a[i].z)	res=a[i].z,op=3;
			if(op==1)	cnta++;
			else if(op==2)	cntb++;
			else			cntc++;
			ans+=res;
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}