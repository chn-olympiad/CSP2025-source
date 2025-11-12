#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
string s;
int a[N],cnt=0;
int main(){
	freopen("number1.in","r",stdin);
	freopen("number1.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt++]=s[i]-48;
		}
	}
	sort(a,a+cnt);
	for(int i=cnt-1;i>=0;i--)  cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*刚来的时候发现自己好像被两位一类中学的大牛夹击了，就我一个来自不知名的二类中学…… 
这回T1好像挺简单的，15分钟就过了
这是我第二次参加CSP了，上回T2差一点就过了，地图探险我***记你一辈子 
要去做T2了，CCF I love you 快保佑我这回至少拿200   */ 
