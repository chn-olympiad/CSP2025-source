#include<bits/stdc++.h>
using namespace std;
int s[105];
bool cmp(int a,int b){
	if(a < b){
		swap(a,b);
	}
	return b < a;
	
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	int ant;
	cin >> n >> m;
	if(n == 1 && m == 1){
		cout << "1 1";
		return 0;
	}
	for(int i = 0;i < n * m;i++){
		cin >> s[i];
	}
	ant = s[0];
	cout << ant << endl;
	sort(s + 1,s + n + 1,cmp);
	for(int i = 0;i < n * m;i++){
		
		if(s[i + 1] > s[i]){
			swap(s[i+1],s[i]);
		}
		cout << s[i] << endl;
		
	}
	for(int i = 0;i < n * m;i++){
		if(ant == s[0]){
			cout << "1 1" << endl;
			return 0;
		}
		if(ant == s[1]){
			cout << "1 2" << endl;
			return 0;
		}
		if(ant == s[2]){
			cout << "2 2" << endl;
			return 0;
		}
		if(ant == s[3]){
			cout << "2 1" << endl;
			return 0;
		}
	}
	return 0;
}
