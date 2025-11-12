#include<bits/stdc++.h>
using namespace std;
long long N,Num,A,B,C;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>N;
	cin>>A>>B>>C;
	for(int i=4;i<=N;i++){
		int q;
		cin>>q;
	}
	if(N<3){
		cout<<0;
		return 0;
	}
	if(N==3){
		if(A+B>C&&A+C>B&&C+B>A){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	for(int i=3;i<=N;i++){
		Num+=(N-i+1);
	}
	cout<<Num;
	return 0;
}
