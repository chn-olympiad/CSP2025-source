#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)	cin>>a[i];
	a[0]=a[1];
	sort(a+1,a+1+n*m,cmp);
	int pos=0;
	for(int i=1;i<=n*m;i++)	
		if(a[i]==a[0])
			pos=i-1;
	int r=1,c=1;
	while(pos--){
		if(r&1)	c++;
		else	c--;
		if(c>m||c<1){
			r++;
			if(r&1)	c=1;
			else	c=m;
		}
//		cout<<pos<<" "<<r<<" "<<c<<"\n";
	}
	cout<<r<<" "<<c;
	return 0;
}
