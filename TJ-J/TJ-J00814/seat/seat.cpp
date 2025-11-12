#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n, m, scr, rank, c, r;
	vector<int> grade(150);
	int seat[20][20];
	cin>>n>>m;
	for(int i = 0; i < n*m; i++){
		cin>>grade[i];
	}
	scr = grade[0];
	for(int i = grade.size()-1; i >= 0; i--){
		for(int j = i; j >=0 ; j--){
			if(grade[j]<grade[i]){
				swap(grade[i],grade[j]);
			}
		}
	}
	for(int i = 0; i<grade.size(); i++){
		//cout<<grade[i]<<endl;
		if(grade[i]==scr)
		rank = i+1;
	}//cout<<r<<' '<<rank<<endl;
	c = ceil(rank*1.0/n);
	cout<<c<<' ';
	r = (rank-1)%n+1;
	if(c%2==0){
		r = n + 1 - r;
	}cout<<r;
    return 0;
}

