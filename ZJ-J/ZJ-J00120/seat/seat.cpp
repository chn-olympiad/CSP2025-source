#include<bits/stdc++.h>
using namespace std;
int n,m,nw,sc,cnt;//~,~,nowcin,R'sScore,R'sID
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>nw;
		if(i==1) sc=nw;
		if(nw>sc) cnt++;
	}
	cnt++;
	int r=cnt/n;
	//cout<<cnt<<endl;
	if(cnt%n!=0){
		r++;
	}
	if(cnt%n==0){
		if(r%2==0){
			cout<<r<<" "<<1;
		}
		else{
			cout<<r<<" "<<n;
		}
	}
	else{
		if(r%2==0){
	//cout<<"A"<<endl;
			cout<<r<<" "<<n-(cnt%n)+1;
		}
		else{
	//cout<<"B"<<endl;
			cout<<r<<" "<<cnt%n;
		}
	}
	return 0;
}
/*
3 4
89 91 94 95 96 97 98 100 99 93 92 90
*/