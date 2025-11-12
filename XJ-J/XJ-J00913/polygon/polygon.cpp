#include<bits/stdc++.h>
using namespace std;
int n;
int stc[5050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	int maxnn = 0;
	for(int i =1;i<=n;i++){
		cin >> stc[i];
		if(maxnn<stc[i]){
			maxnn = stc[i];
		}
	}
	if(n<=3){
		cout << 1;
	}
	else if(maxnn == 1){
		cout <<maxnn *n;
		
	}
	else{
		int ans;
		for(int i =1;i<=n;i++){
			ans += stc[i]; 
		}
		cout <<ans;
	}
	return 0;
}
