#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,p;
	cin>>n>>m;
	vector<int> seat;
	for(int i=0;i<(n*m);i++){
		cin>>a;
		seat.push_back(a);
	}
	a=seat[0];
	sort(seat.begin(),seat.end(),cmp);
	for(int i=0;i<seat.size();i++){
		if(a==seat[i]){
			p=i;
			continue;
		}
	}
	int c,r;
	for(int i=1;i<=n;i++){
		if(p>=(i*m))continue;
		c=i;
		if(i%2==1){
			r=p%m;
			r++;
			break;
		}
		if(i%2==0){
			r=p%m;
			r=m-r;
			break;
		}
	}
	cout<<c<<' '<<r;
	return 0;
}
