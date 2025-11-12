#include<bits/stdc++.h>
using namespace std;
int te[1100];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
 	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int R;
	cin>>R;
	te[1]=R;
	for(int i=2;i<=n*m;i++)cin>>te[i];
	sort(te+1,te+1+n*m,cmp);
	int wh;
	for(int i=1;i<=n*m;i++){
		if(te[i]==R){
			wh=i;
			break;
		}
	}
	int l=wh/n;
	if(wh%n!=0)l++;
	int h=wh%n;
	if(l%2==0)h=(n-h)%n+1;
	else if(h==0)h=n;
	cout<<l<<' '<<h;
	return 0;
}
