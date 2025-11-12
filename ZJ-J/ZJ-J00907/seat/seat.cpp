#include<bits/stdc++.h>
using namespace std;
int s[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int n,m,t=1;
	cin>>n>>m;
	cin>>s[1];
	for(int i=2;i<=n*m;i++){
		cin>>s[i];
		if(s[i]>s[1]){
			t++;
		}
	}
	int x=(t+n-1)/n,y;
	if(x%2==1){
		y=((t-1)%n)+1;
	}
	else{
		y=n-((t-1)%n);
	}
	cout<<x<<' '<<y;
	return 0;
}
