#include <bits/stdc++.h>
using namespace std;
int n,m;
int score[100001];
int sc;
int in_sert;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> score[i];
	}
	sc = score[1];
	if(n == 1 && m == 1){
		cout << "1 1";
	}
	if(n == 1 && m <= 10){
		sort(score + 1,score + (n * m) + 1,cmp);
		for(int i = 1;i <= n * m;i++){
			if(score[i] == sc) in_sert = i;
		} 
		cout << in_sert << " 1";
	}
	if(n <= 10 && m == 1){
		sort(score + 1,score + (n * m) + 1,cmp);
		for(int i = 1;i <= n * m;i++){
			if(score[i] == sc) in_sert = i;
		} 
		cout << "1 " << in_sert;
	}
	return 0;
} 
