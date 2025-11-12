#include <bits/stdc++.h>
using namespace std;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	signed n,m;
	cin>>n>>m;
	signed num=0;
	signed score;
	cin>>score;
	for(signed i=1;i<n*m;i++){
		signed x;
		cin>>x;
		if(score<x){
			num++;
		}
	}
	signed down=num/n+1;
	signed across=num%n+1;
	if(down%2==0){
		across=n-across+1;
	}
	cout<<down<<" "<<across;
	return 0;
}