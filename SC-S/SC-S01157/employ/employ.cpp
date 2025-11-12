#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,sum = 0;
	cin >> n >> m;
	char x[n+5];
	int c[n+5];
	for(int i = 0;i < n;i++){
		cin >> x[i];
		if(x[i] == '1'){
			sum++;
		}
	}for(int i = 0;i < n;i++){
		cin >> c[i];
	}
	cout << sum;
	return 0;
}