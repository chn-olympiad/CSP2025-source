#include<bits/stdc++.h>
using namespace std;

int n,m,a,w;
long long f[200];

bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>f[i];
	}
	a=f[1];
	sort(f+1,f+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(f[i]==a) {
			w=i;	
			break;
		}
	}
	int x=w/n,y=w%n;
	if(w%n) x++;
	if(!y) y=n;
	if(x%2==0) y=n-y+1;
	cout<<x<<' '<<y;
	return 0;
}
