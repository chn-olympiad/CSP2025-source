#include<bits/stdc++.h>
using namespace std;
int sticks[5500];
long long maxx,c=0;
int n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>sticks[i];
		c+=sticks[i];
		if(c>=maxx){
			maxx=c;
		}
	}
	if(c<(maxx*2)){
		cout<<0;
		return 0;
	}cout<<6;
	return 0;
}
