#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000005];
int k = 0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0; i<s.length(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			num[k] = s[i] - 48;
			k++;
		}
	}
	for(int i=1; i<=k-1; i++){
		for(int j=0; j<=k-1; j++){
			int a = 0;
			if(num[j+1] > num[j]){
				a = num[j];
				num[j] = num[j+1];
				num[j+1] = a;
			}
		}
	}
	for(int i=0; i<=k-1; i++) cout << num[i]; 
	return 0;
}
