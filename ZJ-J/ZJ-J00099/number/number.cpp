#include<bits/stdc++.h>
using namespace std;

string s;
int number[1000100];
int num;

bool cmp(int a,int b) {
	return a>b;
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0; i<s.size(); i++) {
		if(s[i]<='9'&&s[i]>='0') {
			number[num]=(int)(s[i]-'0');
			num++;
		}
	}
	sort(number,number+num,cmp);
	for(int i=0; i<num; i++) {
		cout<<number[i];
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
