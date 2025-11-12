#include<bits/stdc++.h>
using namespace std;
struct yl{
	int m1,m2,q1;
}a[1200000];
struct cunlu{
	int cf,N[12000],zf;
}b[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].m1>>a[i].m2>>a[i].q1;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i].cf;
		b[i].zf+=b[i].cf;
		for(int j=1;j<=n;j++){
			cin>>b[i].N[j];
			b[i].zf+=b[i].N[j];
		}
	}
	
	int p1=0;
	for(int i=1;i<=n;i++){
		p1+=a[i].q1;
	}
	int p2=1000000000;
	for(int i=1;i<=k;i++){
		p2=min(p2,b[i].zf);
	}
	int p3=1000000000;
	for(int j=1;j<=k;j++){
		int ok=0;
		for(int i=1;i<=m;i++){
			int o=b[j].N[a[i].m1]+b[j].N[a[i].m2];
			if(o<a[i].m1){
				ok+=o;
				b[j].N[a[i].m1]=0;
				b[j].N[a[i].m2]=0;
			}else ok+=a[i].m1;
		}
		p3=min(p3,ok+b[j].cf);
	}
	
	cout<<min(min(p1,p2),p3);
	
	
	
	return 0;
}

