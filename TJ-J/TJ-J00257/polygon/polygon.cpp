#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4;
int leng[MAX];
string to2(long long n){
	string s = "";
	while(n){
		int a = n % 2;
		if(a == 1){
			s = "1" + s;
		}
		else{
			s = "0" + s;
		}
		n /= 2;
	}
	while(s.length() < 5){
		
		s = "0" + s;
	}
	return s;
}

// 5
// 1 2 3 4 5
// 5
// 2 2 3 8 10
//
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n , ans = 0;
	cin >> n;
	for(int i = 0;i < n;i ++){
		cin >> leng[i];
	}
	long long top = 0;
	for(int i = 0;i < n;i ++){
		top += pow(2,i);
	}
	for(long long i = 1;i <= top;i ++){
		string s = to2(i);
//		cout << s << "\n";
		int one_cnt = 0;
		for(int j = 0;j < s.length();j ++){
			if(s[j] == '1'){
				one_cnt ++;
			}
		}
		if(one_cnt < 3){
			continue;
		}
		int sum = 0 , max_leng = 0;
		for(int j = 0;j <= s.length();j ++){
			if(s[j] == '1'){
				sum += leng[j];
				max_leng = max(max_leng , leng[j]);
//				cout << "choose ->" << leng[i] << "\n";
			}
		}
//		cout << "max == " << max_leng << "\n";
		if(sum > max_leng * 2){
			ans ++;
		}
	}
	cout << ans << "\n";
	
	
	
	
	
	return 0;
}

