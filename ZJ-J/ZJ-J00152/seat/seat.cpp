#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,total;
	cin>>n>>m;
	total=n*m;
	int a[105];
	for(int i=1;i<=total;i++){
		cin>>a[i];
	}
	int w=1;
	for(int i=1;i<total;i++){
		for(int j=i+1;j<=total;j++){
			if(a[i]<a[j]){
				if(i==w) w=j;
				swap(a[i],a[j]);
			}
		}
	}
	int c,r;
	c=w/n;
	if(w%n!=0) c++;
	r=w-(c-1)*n;
	if(c%2==0) r=n+1-r;
	cout<<c<<' '<<r;
	return 0;
}
