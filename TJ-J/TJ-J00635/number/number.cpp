#include<bits/stdc++.h>
using namespace std;
string s1;//原始数据
int a[1000005];//只剩数字后的数据
int t=0;//数组下标
bool cmp(int x,int y){
	return x>y;//从大到小
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);//神秘小代码(记得检查！！！！！！！！)
	cin>>s1;
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9'){//判断是否为数字
			a[t++]=(s1[i]-'0');
		}
	}
	sort(a+0,a+t,cmp);//排序(确保最大)
	for(int i=0;i<t;i++){
		cout<<a[i];//输出
	}
	//求求你了，别爆零行吗(QAQ) 
	return 0;
}
