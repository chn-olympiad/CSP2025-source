//刘庭宇 西安市高新第一学校 SN-J00106
#include<bits/stdc++.h>
using namespace std;
int a[10000010];
int t=1;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[t]=s[i]-'0';
			t++;
		}
	}
	t--;
	sort(a+1,a+t+1);
	for(int i=t;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
