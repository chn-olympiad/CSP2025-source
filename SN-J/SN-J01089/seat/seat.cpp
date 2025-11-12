#include<bits/stdc++.h>
using namespace std;
long long N,M,Num,Q,W,Num2,res1,res2;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>N>>M;
	int K;
	cin>>K;
	for(int i=2;i<=N*M;i++){
		int q;
		cin>>q;
		a[q]++;
	}
	for(int i=100;i>K;i--){
		Num+=a[i];
	}
	Num2=Num;
	while(Num2>=N){
		Num2-=N;
		res1++;
	}
	res2=Num-res1*N;
	Q=res1+1;
 	W=res2;
	cout<<Q<<" ";
	if(Q%2==0){
		cout<<N-W;
	}else{
		cout<<W+1;
	}
	return 0;
}
