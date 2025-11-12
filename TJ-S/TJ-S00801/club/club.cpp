#include<bits/stdc++.h>
using namespace std;
long long n,m,i,a,b,x,y,z,j,k,l[10010],o,p,s,c;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>m;
	for(i=0;i<m;i++){
		cin>>n;
		if(n==2){
			cin>>x>>y>>z>>a>>b>>c;
			cout<<max(a,max(b,c))+max(x,max(y,z))<<'\n';
		}
		for(j=0;j<n;j++){
			cin>>x>>y>>z;
			if(y==0&&z==0){
				l[i]=x;
				c=123;
			}
		}
		if(c==123){
			sort(l,l+n);
			c=0;
			for(i=n/2-1;i>=0;i++){
				c+=l[i];
			}
			cout<<c<<"\n";
		}
		
	}
	return 0;
}
