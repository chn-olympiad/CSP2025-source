#include<bits/stdc++.h>
using namespace std;
int score[106] = {};
int xiaoming = 0;
int seat;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < n*m;i++){
		cin >> score[i];
		if(i == 0){
			xiaoming = score[i];
		}
	}
	//cout << xiaoming;//--------------
	int numbers = n * m;
	sort(score,score+numbers);
	for(int i = n*m-1;i >=0;i--){
	//	cout << score[i];//--------------
		if(score[i] == xiaoming){
			seat = numbers - i;
		}
	}
	//cout << seat;//-----------
	int yu = seat%n;
	int shang = (seat-1)/n;
	int pass;
	if(shang % 2 == 0){
		if(yu == 0){
			pass = n;
		}
		else{pass =yu;}
	}
	if(shang % 2 == 1){
		pass = n-yu+1;
		if(yu == 0){
			pass = 1;
		}
	}

	cout << shang+1 << " " << pass;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
