#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e3+99;
int a[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,num;
	cin>>n>>m;
	num=n*m;
	for(int i=1;i<=num;i++){
		cin>>a[i];
	}
	long long score=a[1];
	long long seat;
	//cout<<score<<endl;
	sort(a+1,a+num+1);
	for(int i=1;i<=num;i++){
		if(a[i]==score){
			seat=i;
			break;
		}
	}
	seat=num-seat+1;
	//cout<<"HHHERE "<<seat<<endl;
	//cout<<seat<<endl;
	long long cnt=0;
	while(seat>n){
		seat-=n;
		cnt++;
	}
	cout<<cnt+1<<" ";
	if(cnt%2==0){
		cout<<seat<<endl;
	}else{
		cout<<n-seat+1<<endl; 
	} 
	//cout<<"HERE"<<" "<<seat<<" "<<cnt<<endl;
	return 0;
}

/*
3 3
94 95 96 97 98 99 100 93 92

3 2
97 98 99 96 95 100 

6 5 
15 1 2 3 4 5 6 7 8 9 10 11 12 13 14 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
*/
