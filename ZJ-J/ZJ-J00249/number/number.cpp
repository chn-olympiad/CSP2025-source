#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int> num;
	int cnt=0;
	for (int i=0;i<s.size();i++){
		if (s[i]<='9'&&s[i]>='0'){
			cnt++;
			num.push_back(s[i]-'0');
		}
	}
	sort(num.begin(),num.end(),cmp);
	for (int i=0;i<cnt;i++){
		cout<<num[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
