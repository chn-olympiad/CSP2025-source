#include<bits/stdc++.h>
using namespace std;
struct road{
	int a,b,f;
}a[1000000+10];
struct cun{
	int f;
	int l[1000];
}c[10];
bool t(road a,road b)
{
	return a.f<b.f;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
    

	for(int i=0;i<m;i++){
		cin>>a[i].a>>a[i].b>>a[i].f;
	}
	for(int i=0;i<k;i++){
		cin>>c[i].f;
		for(int j=0;j<n;j++){
			cin>>c[i].l[j];
		}
	}
	
	
	for(int i=0;i<m;i++){
		int minn=100000000;
		for(int j=0;j<k;j++){
			minn=min(c[j].l[a[i].a]+c[j].l[a[i].b]+c[j].f,minn);
		}
		a[i].f=min(a[i].f,minn);
	}
		
	int sum=0;
	sort(a,a+m,t);

	for(int i=0;i<(n-1);i++){
		sum+=a[i].f;
	}

	cout<<sum;
	return 0;
}
