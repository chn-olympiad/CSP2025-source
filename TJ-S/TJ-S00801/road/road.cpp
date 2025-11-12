#include<bits/stdc++.h>
using namespace std;
long long n,m,i,a,b,x,y,z,j,k,l[10010],o,p,s,c;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(i=0;i<m;i++){
		cin>>a>>b>>c;
		s+=c;
	}
	cout<<s;
	return 0;
}
