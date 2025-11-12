#include<bits/stdc++.h>
using namespace std;
string a;
int t[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);//文件输入输出 
	cin>>a;
	for(int i=0;i<a.size();i++){//遍历 
		if(a[i]>='0'&&a[i]<='9'){//查找数字 
			t[a[i]-'0']++;//标记数字 
		} 
	}
	for(int i=9;i>=0;i--){//从大到小输出 
		for(int j=0;j<t[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
