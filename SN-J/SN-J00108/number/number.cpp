#include <iostream>//执行导入库操作 
#include <cstiudo>//执行导入库操作 
using namespace std;//执行定义命名操作空间 
int a[1000005];//定义大小为1*10^6的数组 
int main()//主函数 
{
	freopen("number.in".r,number.cpp);//执行读操作 
	freopen("mnumber.out".w,number.cpp);//执行写操作 
	string s;//输入字符串s 
	for(int i=1;i<=s.size();i++){//执行循环判断大小写操作 
		cin>>s[i];//循环输入字符串s中的项 
		if('A'<=s[i]&&s[i]<='Z'){//开始判断大小写 
			cout<<s[i];//判断是小写字母，则直接正常输出 
		}else{//通过ASCLL码， 判断是大写，执行下一步操作 
			cout<<(s[i]=(char)'A'&&s[i]=(char)'Z');//强制类型转换 
		}
	}//判断循环结束 
	return 0;//返回值0 
}
