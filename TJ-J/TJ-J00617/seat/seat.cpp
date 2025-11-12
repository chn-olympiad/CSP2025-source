#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long sts;
int score,x,ratio=1;
int ne,me;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sts=n*m;
	cin>>score;
	for(int i=1;i<sts;i++){
		cin>>x;
		if(x>score){
			ratio++;
		}
	}
	ratio--; 
	me=ratio/n;
	me++;
	if(me%2==0){
		ne=n-ratio%n;
	}
	else ne=ratio%n;
	ne++;
	cout<<me<<" "<<ne;
	return 0;
}


























//qwq 
