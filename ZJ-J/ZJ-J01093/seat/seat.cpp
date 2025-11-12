#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a[N],pos,tag,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	tag=a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	for(int i=1;i<=n*m;++i){
		if(a[i]==tag){
			pos=i;
		}
	}
	int x=pos/n;
	pos%=n;
	if(!pos){
		if(x%2==1)y=n;
		else y=1;
	}
	else{
		if(x%2==1) y=n+1-pos;
		else y=pos;
		x++;
	}
	cout<<x<<" "<<y;
	return 0;
}