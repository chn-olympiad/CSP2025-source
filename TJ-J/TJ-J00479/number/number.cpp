#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str = "";
	cin >> str;
	if(str.size() == 1){
		cout << str;
		return 0;	
	}
	string a = "";
	for(int i=0;i<str.size();i++){
		if(str[i]>='0' && str[i]<='9')
			a += str[i];
	}
	int s = a.size();
	int arr[s + 10];
	for(int i=0;i<s;i++){
		arr[i] = (int)(a[i]-'0');
	}
	sort(arr,arr + s);
	for(int i=s-1;i>=0;i--){
		cout << arr[i];
	}
	return 0;
}
