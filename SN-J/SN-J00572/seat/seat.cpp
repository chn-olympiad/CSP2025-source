#include<bits/stdc++.h>
using namespace std;
int main(){
	int s[50];
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n*m;i++){
			cin >> s[i];
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<m;j++){
			//sort(s[i],s[j]);
			cout << s[i] << ' ' << s[j];
		}
	}
}
