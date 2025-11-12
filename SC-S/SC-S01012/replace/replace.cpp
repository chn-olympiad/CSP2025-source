#include<bits/stdc++.h>
using namespace std;
int t=765437,T,ax,in,a,b,c,n;
int randnum;
int randd(int n){
	randnum = rand()%n+t*n-rand()*rand()*n+randnum;
	if(randnum<0)randnum=-randnum*n;
	randnum += (rand()*randnum)%(rand()*rand()*n);
	randnum = randnum*randnum%rand()*randnum-rand();
	return randnum;
}
int random(int a,int b){
//	long long int num = randd(rand()+rand());
//	while(num<b){
//		num += (rand()*a)%(rand()+200000);
//	}
int num = rand()*rand()*t;
num = abs(num);
if(a>b){
	swap(a,b);
}
	return num%(b-a)+a;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> t;
	cin >> ax;
	t *= ax*rand();
	for(int i=1;i<=ax;i++)cout << random(5,100);
	return 0;
}