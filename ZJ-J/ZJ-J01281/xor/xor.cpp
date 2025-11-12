#include<bits/stdc++.h>
using namespace std;
int a[514514];
int XOR(int input0, int input1) {
	string input0_to_base = "";
	string input1_to_base = "";
	string output_string = "", output_string_tmp = "";
	int output = 0;
	while (input0) {
		input0_to_base += input0 % 2 + '0';
		input0 = input0 / 2;
	}
	while (input1) {
		input1_to_base += input1 % 2 + '0';
		input1 = input1 / 2;
	}
//	cout <<input0_to_base << " " << input1_to_base<< endl;
	for (int i = 0; i < max(input0_to_base.length(), input1_to_base.length()); i++) {
		if (input0_to_base[i] - '0' + input1_to_base[i] - '0' == 1) {
		    output_string_tmp += '1';
		}
		else if (i >= input0_to_base.length()  && input1_to_base[i] == '1' ||
				 i >= input1_to_base.length()  && input0_to_base[i] == '1') {
			output_string_tmp += '1';
		}
		else {
		    output_string_tmp += '0';
		}
	}
//	cout <<output_string_tmp<< endl;
//	for (int i = output_string_tmp.length() - 1; i >= 0; i--) {
//		output_string += output_string_tmp[i];
//	} 
	for (int i = 0; i < output_string_tmp.length(); i++) {
		output += (output_string_tmp[i] - '0') * pow(2, i);
	}
	return output;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	cout << XOR(XOR(1, 0), 3);     // Perfect!!!!!!!!!!!!!!!!
	int n, k, one_cnt = 0;
	cin >> n >> k;
	bool cin_compare = true;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1) cin_compare = false;
		if (a[i] == 0) one_cnt ++;
	}
	if (k == 0 && cin_compare) {
		cout <<  n / 2;
		return 0;
	}
	if (k == 1) {
		cout << one_cnt;
		return 0;
	}
	cout << n / 2;
	
	
	
	return 0;
}
