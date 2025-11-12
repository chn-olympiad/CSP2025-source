#include<iostream>
#include<algorithm>
using namespace std;
int a[1000010];
int main (){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++){
	int idx=0;
		if(s[i]>='0'&&s[i]<='9'){
			a[++idx]=s[i]-'0';
		}
	}
	sort(a+1,a+idx+1,greater<int>());
	for(int i=1;i<=idx;i++){
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
