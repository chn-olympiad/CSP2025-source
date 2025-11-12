#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int scores[n*m+4];
	for(int i=1;i<=n*m;i++)cin>>scores[i];
	int Rscore=scores[1];
	sort(scores+1,scores+1+n*m);
	int index=1;
	for(int i=n*m;i>=1;i--){
		if(scores[i]==Rscore){
			index=i;
			break;
		}
	}
	index=n*m-index;
	int c=int(floor(index/1.0/n))+1;
	int r;
	if(c%2==1)r=index%n+1;
	else r=n-index%n;
	cout<<c<<" "<<r;
	
	return 0;
}