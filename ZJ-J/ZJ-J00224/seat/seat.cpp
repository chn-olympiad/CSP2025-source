//luogu UID:916276
#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[105];
int Rscore;

bool cmp(int a,int b){
	return a > b;
}
void print(int id){
	ofstream cout("seat.out");
//	cout<<"id="<<id<<"(Must delete it!)\n";
	int x = (id - 1) / n + 1;
	cout<<x<<" ";
	if(x % 2){
		cout<<(id - 1) % n + 1;
	}else{
		cout<<n - (id - 1) % n;
	}
}

int main(){
	ifstream cin("seat.in");
	ofstream cout("seat.out");
	cin>>n>>m;
	for(int i = 1;i <= n * m;i++){
		cin>>a[i];
	}
	Rscore = a[1];
//	cout<<"Rscore="<<Rscore<<"(Must delete it!)\n";
	sort(a+1,a+(n * m)+1,cmp);
	for(int i = 1;i <= n * m;i++){
//		cout<<"Try a["<<i<<"]="<<a[i]<<"!(Must delete it!)\n";
		if(a[i] == Rscore){
			print(i);
			return 0;
		}
	}
	return 0;
}
