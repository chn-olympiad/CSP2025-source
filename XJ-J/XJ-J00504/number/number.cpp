#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number1.in","r",stdin);
	freopen("number1.out","w",stdout);
	int num[100010];
	int a = 0;
	string n;
	cin >> n;
	if(n.size()==1){
		cout << n;
	}
	for(int i = 0;i<n.size();i++){
		int f = n[i] - 48;
		if(f<49){
			num[a] = f;
			a++;
		}
	}
	int h=0;
	for(int i = 0;i<a;i++){
		for(int j = i+1;j<=a;j++){
			if(num[i] < num[j]){
				h = num[i];
				num[i] = num[j];
				num[j] = h;
			}
		}	

	}
	for(int i = 0;i<a;i++){
		cout << num[i];
	}
	return 0;
} 
