#include <bits/stdc++.h> 

using namespace std;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;//输入字符串 
	int len=s.size();//获取长度 
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;//统计数字出现次数 
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;//数字从大到小按次数输出 
		}
	}
	return 0;
}
