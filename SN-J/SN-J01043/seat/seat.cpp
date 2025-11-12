#include<bits/stdc++.h>
using namespace std;

int n,m,ji,goal,index;

int score[105];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	ji = n * m;
	for(int i = 1;i <= ji;++i){
		cin >> score[i];
	}
	goal = score[1];
	sort(score + 1,score + ji + 1,cmp);
	
//	for(int i = 0;i <= ji+1;++i){
//		cout << score[i] << ' ';
//	}
//	cout << endl;

	index = 1;
	while(score[index] != goal){
		++index;
	}
	
//	cout << "index:" << index << endl;

	int lie,hang;
	lie = (index / (2 * n)) * 2;
	index %= (2 * n);
	if(index == 0){
		hang = n;
	}
	else if(index >= 1 && index <= n){
		++lie;
		hang = index;
	}
	else if(index > n && index <= 2*n){
		lie += 2;
		hang = 2 * n - index + 1;
	}
	cout << lie << ' ' << hang;
	return 0;
}
