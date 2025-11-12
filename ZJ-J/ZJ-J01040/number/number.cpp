#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> num;
int cnt;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			num.push_back(s[i]-'0');
		}
	}
	sort(num.begin(),num.end());
	for(int i=cnt-1;i>=0;i--)
		cout<<num[i];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}