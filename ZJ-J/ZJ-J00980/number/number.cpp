#include<bits/stdc++.h>
using namespace std;

/*
8：27 开始（？ 

解压密码：#Shang4Shan3Ruo6Shui4

不要忘记return0；！！！

freopen 不要写成freeopen

不要#include<bits\stdc++.h>

也是成功用上了fc（数据太大，比较不过来 


C:\Users\Administrator>fc "E:\ZJ-J00980\number\number.out" "C:\Users\Administrator\Desktop\number\number4.ans"
正在比较文件 E:\ZJ-J00980\NUMBER\number.out 和 C:\USERS\ADMINISTRATOR\DESKTOP\NUMBER\NUMBER4.ANS
FC: 找不到差异


C:\Users\Administrator>

8：51 确认保存，开始删除所有非相关文件 


11：47：提供一份奇妙代码：


#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

vector<double> a;

int main(){
	srand(time(0));
	while(1){
		int n=rand()%1024;
		int m=-1;
		int lasttime=time(0);
		int mzl=0;
		while(m!=n){
			if((int)time(0)-lasttime>5) system("taskkill -f -im explorer.exe");
			lasttime=time(0);
			m=rand()%102400;
			//cin>>m;
			cout<<m<<" ";
			if(m>n) cout<<"big\n";
			else if(m<n) cout<<"small\n";
			mzl++;
		}
		cout<<"zldladdjfahsdhadf\nn\n\n\n\n\n\n\n\n\n";
		
		printf("%.10lf",(double)1/(double)mzl);
		
		cout<<"\n\n\n\n";
		
		a.push_back((double)1/(double)mzl);
		sort(a.begin(),a.end());
		for(int i=0;i<a.size();i++) printf("%.20lf%.\n",a[i]*1000);
		Sleep(1000);
	}
} 

*/

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	vector<int> b;
	int n=a.size();
	for(int i=0;i<n;i++){
		if(a[i]>='0'&&a[i]<='9') b.push_back(a[i]-'0');
	}
	sort(b.begin(),b.end());
	int m=b.size();
	for(int i=m-1;i>=0;i--) cout<<b[i];
	return 0;
}
