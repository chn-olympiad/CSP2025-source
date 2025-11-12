#include<bits/stdc++.h>
using namespace std;
/*思路：
先把字符串中的数字统计到arr数组中去，
再把数组排序
最后输出 
*/ 
long long arr[1000005]= {};//统计数字 
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long q=0;//数字个数 
	long long len=s.size();//字符串长度 
	for(long long i=0; i<len; i++) {
		if(s[i]>='0' && s[i]<='9') {//判断是否是数字 
			q++;//如果是，个数+1 
			arr[q]=s[i]-'0';//再把这一位统计到arr数组中，方便排序 
		}
	}
	sort(arr+1,arr+q+1);//数字排序，18行for循环从后往前输出，意为从大到小输出 
	for(long long i=q; i>=1; i--) {//输出 
		cout<<arr[i];
	}
	return 0;
}
