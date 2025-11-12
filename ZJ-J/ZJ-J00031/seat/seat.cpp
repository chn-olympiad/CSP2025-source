#include<bits/stdc++.h>
using namespace std;

int n,m,c=1,r=1,score,a[15];

bool compare(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	score=a[1];
	sort(a+1,a+1+n*m,compare);
	for(int i=1;i<=n*m;i++){
		if(a[i]==score){
			cout<<c<<' '<<r;
			return 0;
		}
		if(i%n==0)
			c++;
		else if(c%2==1)
			r++;
		else if(c%2==0)
			r--;
	}
	return 0;
}