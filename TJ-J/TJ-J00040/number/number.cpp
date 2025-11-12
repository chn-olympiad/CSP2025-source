#include<bits/stdc++.h>
using namespace std;
string s;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int a[1000005];
	int l = 0;
	int tcnt = 0;
	for(int i = 0 ; i < s.size() ; i++){
		/*if(s[i] != '0' || s[i] != '1' || s[i] != '2' || s[i] != '3' || s[i] != '4' || s[i] != '5' || s[i] != '6' || s[i] != '7' || s[i] != '8' || s[i] != '9'){
			continue;
		}*/
		if(s[i] == '0'){
			tcnt++;
		}
		if(s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9'){
			a[i + 1] = s[i] - 48;
			l++;
			continue;
		}
		
	}
	sort(a + 1,a+l,cmp);
	/*for(int i = 0 ; i < l ; i++){
		for(int j = 1 ; j < l ; j++){
			if(a[i] > a[i - 1]){
				swap(a[i],a[i - 1]);
			}
		}
	}*/
	for(int i = 1 ; i <= l ; i++){
		cout << a[i];
	}
	for(int i = 1 ;i <= tcnt ; i++){
		cout << "0";
	}
	return 0;
}
