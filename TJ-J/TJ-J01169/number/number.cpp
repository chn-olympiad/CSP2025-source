#include<bits/stdc++.h>
using namespace std;
int cnt[10];//桶排序 
char num[10]={'0','1','2','3','4','5','6','7','8','9'};//输出查找 
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	string s;//输入的字符串 
	cin>>s;
	int l=s.size();//字符串长度 
	
	for(int i=0;i<l;i++){
		int x=s[i]-'0';//转成数字 
		if(x>=0&&x<=9){
			cnt[x]++;//是数字就存起来 
		}
	}
	
	for(int i=9;i>=0;i--){//从大到小遍历cnt数组 
		for(int j=cnt[i];j>0;j--){//cnt[i]=？就输出几个 
			cout<<num[i];//输出char类型，防止超long long 
		}
	}
	cout<<endl;
	
	return 0;
	
} 
