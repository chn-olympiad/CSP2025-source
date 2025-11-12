#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;//输入 
	for(int i=0;i<s.size();i++){//遍历该字符串 
		if(s[i]!='1'&&s[i]!='2'&&s[i]!='3'&&s[i]!='4'&&s[i]!='5'&&s[i]!='6'&&s[i]!='7'&&s[i]!='8'&&s[i]!='9'&&s[i]!='0'){//特殊字符进行特殊赋值 
			a[i]=1000;//特殊值 （以免0和字母混和） 
			continue;
		}
		//如果是数字（1，2，3，4，5，6，7，8，9，0），逐个判断 
		if(s[i]=='1'){ 
			a[i]=1;
			continue;
		}
		if(s[i]=='2'){
			a[i]=2;
			continue;
		}
		if(s[i]=='3'){
			a[i]=3;
			continue;
		}
		if(s[i]=='4'){
			a[i]=4;
			continue;
		}
		if(s[i]=='5'){
			a[i]=5;
			continue;
		}
		if(s[i]=='6'){
			a[i]=6;
			continue;
		}
		if(s[i]=='7'){
			a[i]=7;
			continue;
		}
		if(s[i]=='8'){
			a[i]=8;
			continue;
		}
		if(s[i]=='9'){
			a[i]=9;
			continue;
		}
		if(s[i]=='0'){
			a[i]=0;
			continue;
		}
	}
	//判断完毕，数字/特殊值已经全部在A数组中 
	sort(a,a+s.size());//对A数组排序，最大的数放前面 
	for(int i=s.size()-1;i>=0;i--){//sort排序是先小后大，所以使用倒序 
		if(a[i]==1000){//判断特殊值 
			continue;//是就跳过 
		}
		cout<<a[i];//不是就输出 
	}
	return 0;
}
