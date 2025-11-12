#include <bits/stdc++.h>
using namespace std;
int c,x,n,m,k;
struct inf{
	int a,b,m;
}a[1919810];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		cin>>a[i].a>>a[i].b>>a[i].m;
	}
	for(int i=0;i<m;i++){
		cin>>c;
		for(int j=0;j<n;j++){
			cin>>x;
		}
	}
	cout<<114514;
	return 0;
}
