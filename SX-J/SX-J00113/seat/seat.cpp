#include<bits/stdc++.h>
using namespace std;
int q[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int z=n*m;
	for(int i=1;i<=z;i++) cin>>q[i];
	int w=q[1];
	sort(q+1,q+z+1);
	int p=0;
	for(int i=z;i>=1;i--){
		p++;
		if(q[i]==w) break;
	}
	int l=p%n;
	if(l==0) cout<<p/n<<" ";
	else cout<<p/n+1<<" ";
	int k=p%m;
	if(k==0) {
		if(p/m%2==0) cout<<1;
		else cout<<m;
	}
	else{
		if(((p-k)%m)%2!=0) cout<<(p-k)%m;
		else cout<<m-((p-k)%m+1);
	}
	return 0;
}
