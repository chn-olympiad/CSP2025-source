#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s[1010],c=1,r=1;
	cin >>n>>m;
	for(int i=1;i<=n*m;i++)
		cin >>s[i];
	for(int i=2;i<=n*m;i++){
		if(s[1]<s[i])
			r++;
		if(r>n){
			c++;
			r=r-n+1;
		}
	}
	cout <<c<<" "<<r<<endl;
	return 0;
}
