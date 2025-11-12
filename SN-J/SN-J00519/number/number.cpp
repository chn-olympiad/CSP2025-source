#include<bits/stdc++.h>
using namespace std;
char input[1000005] = {};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	int num = 0;
	cin >> input;
	int i = 0;
	while(true){
		if(input[i] >= 48 && input[i] <= 57){
			input[num] = input[i];
			num++;
		}
		i++;
		if(i >= 1000005){
			break;
		}
	}
	sort(input,input+num);
	for(int i = num-1;i>=0;i--){
		cout << input[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
