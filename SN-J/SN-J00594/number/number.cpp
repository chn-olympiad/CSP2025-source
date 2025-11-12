//姓名：杜悦菲
//考号：SN-J00594
//学校：西安市曲江第一学校 

#include<bits/stdc++.h>
using namespace std;
int num[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int loc=0;
	for(int i=0;i<s.size();i++){
		if((s[i]>='0')&&(s[i]<='9')){
			num[loc]=s[i]-'0';
			loc++;
		}
	}
	sort(num,num+loc);
	for(int i=loc-1;i>=0;i--){
		cout<<num[i];
	} 
	return 0;
}
