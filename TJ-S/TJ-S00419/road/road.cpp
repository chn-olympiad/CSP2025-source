#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a,b,c[114514];
	for(int i=0;i<n;i++){
		cin>>a>>b>>c[i];
	}
	sort(c,c+n);
	int cnt=0;
	for(int i=0;i<n-1;i++){
		cnt+=c[i];
	}cout<<cnt; 
	return 0;
}
