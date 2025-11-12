#include <iostream>
#include <vector>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int seat=n*m;
//	vector<int>a(seat,0);
	int current=0;
	int R;
	cin>>R;
	for(int i=0;i<n*m-1;i++){
		int a;
		cin>>a;
		if(a>R){
			current++;
		}
	}
	current+=1;
	int temp=0;
	int tempm=0;
	int tempn;
	while(current>=temp+n+1){
		temp+=n;
	}
	if(current%n==0){
		tempm=current/n;
	}else{
		tempm=current/n+1;
	}
	if(tempm%2==0){
		tempn=n-(current-temp)+1; 
	}else{
		tempn=current-temp;
	}
	cout<<tempm<<" "<<tempn;
	return 0;
}
