#include<bits/stdc++.h>
using namespace std;
int a[999],n,m;

bool csp(int l,int r){
	return l>r;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	int x=a[1];
	sort(a+1,a+n*m+1,csp);
	for(int i=1;i<=n*m;i++) 
		if(a[i]==x) {
			int l=floor(i/n)+1;
			if(i%n==0) l--;
			int g=i-(l-1)*n;
//			cout<<"i="<<i<<" "<<"l="<<l<<" "<<"g="<<g<<" "<<"n-g="<<n-g<<"\n";
			cout<<l<<" ";
			if(l%2==1) cout<<g;
			else 	   cout<<n-g+1;
			return 0;
		}
	
	return 0;
}

