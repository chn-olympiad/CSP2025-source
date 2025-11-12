#include<bits/stdc++.h>
using namespace std;
int yuan[1000006];
int b[1000006];
struct lu{
	int a;
	int b;
	int q;
}a[1000006];
bool f(lu a,lu b){
	return a.q<b.q;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	cin>>n;
	int m;
	cin>>m;
	int p;
	cin>>p;
	for(int i = 1;i<=m;i++){
		cin>>a[i].a>>a[i].b>>a[i].q;
		sort(a+1,a+n+1,f);
	}
	long long k;
	for(int i = 1;i<=n-2;i++){
		k = k+a[i].q;
	}
	long long minn;
	for(int i = 1;i<=p;i++){
		cin>>yuan[i];
		for(int j = 1;j<=n;j++){
			cin>>b[j];
		}
			
	}
}

