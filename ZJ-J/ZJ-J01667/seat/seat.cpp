#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int c[105],zf,w;
	for(int i=1;i<=n*m;i++)cin>>c[i];
	zf=c[1];
	sort(c+1,c+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(c[i]==zf){
			w=i;
		}
	}
	int x=(w-1)/n+1;
	int y=x%2==0?(n-(w-1)%n):((w-1)%n+1);
	cout<<x<<" "<<y;
	return 0;
}