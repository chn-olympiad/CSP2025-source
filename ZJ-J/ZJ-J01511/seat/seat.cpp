#include<bits/stdc++.h>
using namespace std;
int n,m;
struct pnt{
	int v,n;
}p[10001];
bool cmp(pnt a,pnt b){
	if(a.v<b.v)return 0;
	return 1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>p[i].v;
		p[i].n=i;
	}
	sort(p+1,p+1+n*m,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		//cout<<"--"<<p[i].v;
		if(p[i].n==1){
			x=(i+n-1)/n;
			y=i-(x-1)*n;
			if(x%2==0)y=n-y+1;
			break;
		}
	}
	cout<<x<<" "<<y;
}