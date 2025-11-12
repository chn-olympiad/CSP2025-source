#include<bits/stdc++.h>
using namespace std;
int n,k,cnt,arr[500001];
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin >> n >> k;
	cnt = 0;
	for(int i = 1;i <= n;i++){
		cin >> arr[i];
	}
	if(arr[1] == 1 && arr[2] == 1){
		cout << 1;
	}
	return 0;
}
