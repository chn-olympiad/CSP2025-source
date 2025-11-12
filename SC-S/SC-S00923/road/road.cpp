#include<bits/stdc++.h>
using namespace std;
struct stu{
	long long a,b,c;
};
long long c[15],a[15][10004];
long long n,m,k;
stu a[10004];
vector<long long> v[10004];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
		v[a].push_back(b);
		v[b].push_back(a);
		
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	
	
	return 0;
}