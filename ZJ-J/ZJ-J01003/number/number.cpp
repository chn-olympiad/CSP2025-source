#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e6+10;
string s;
i64 Count = 1;
int Arr[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	for(int i=0;i<=s.length();i++){
		int temp = int(s[i])-48;
		if(temp>=0 && temp<=9){
			Arr[Count++]=temp;
		}
	}
	sort(Arr+1,Arr+Count);
	for(int i=Count-1;i>=1;i--){
		cout << Arr[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}