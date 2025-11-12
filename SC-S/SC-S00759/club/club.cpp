#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int b[5];
int pos=1;
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	int n;
	cin >>n;
	for(int i = 1;i<=n;i++){
		cin >> b[i];
		for(int j = pos;j<=b[i]+pos-1;j++){
			for(int k = 1;k<=3;k++){
				cin >> a[j][k];
			}
		}
		pos+=b[i];
	}
	pos = 1;
	for(int i = 1;i<=n;i++){
		for(int j = pos;j<=b[i]+pos-1;j++){
			for(int k = 1;k<=3;k++){
				cout <<a[j][k]<<" ";
			}
		}
		pos+=b[i];
	}
	/*
	for(int i = 1;i<=n;i++){
		for(int j = pos;j<=b[i]+pos-1;j++){
			for(int k = 1;k<=3;k++){
				cout <<a[j][k]<<" ";
			}
			cout << endl;
		}
		pos+=b[i];
	}
	*/
    //给点分
	return 0;
}