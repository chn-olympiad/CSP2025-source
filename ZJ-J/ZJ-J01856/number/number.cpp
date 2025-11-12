#include<bits/stdc++.h>
using namespace std;
string s;
int num[2000007];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int weishu=s.size();
	int h=0;
	for(int i=0;i<weishu;i++){
		if(s[i]<='9' && s[i]>='0'){
			h++;
			num[h]=s[i]-'0';
		}
	}
	std::sort(num+1,num+1+h,greater<int>());
	for(int i=1;i<=h;i++){
		cout<<num[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
