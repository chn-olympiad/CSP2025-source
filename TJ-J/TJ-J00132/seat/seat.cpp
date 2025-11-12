# include<bits/stdc++.h>
using namespace std;
int n,m,a,b,cnt=1,l,h;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<n*m;i++){
		cin>>b;
		if(b>a){
			cnt++;
		}
	}
	if(cnt%n!=0){
		l=cnt/n+1;
		if(l%2==0){
			h=n+1-(cnt%n);
		}
		else{
			h=cnt%n;
		}
	}
	else if(cnt%n==0){
		if((cnt/n)%2==0){
			l=cnt/n;
			h=1;
		}
		else{
			l=cnt/n;
			h=n;
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
