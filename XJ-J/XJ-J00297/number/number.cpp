#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;

void IOP(){
	cin.tie(0) ,cout.tie(0);
	ios::sync_with_stdio(0);
}

void frop(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
}

string s;
const int N = 1e6+5;
int a[N],c0;

int main(){
	frop();//必须检查 必须检查 必须检查 必须检查 必须检查 必须检查 必须检查 必须检查 必须检查 必须检查 必须检查 必须检查 
	IOP();//注意C风格输入输出 注意C风格输入输出 注意C风格输入输出 注意C风格输入输出 注意C风格输入输出 注意C风格输入输出 
	
	cin>>s;
	int l = s.size(),tot = 0;
	for(int i=0;i<l;i++){
		if(isdigit(s[i])){
			if(s[i] == '0')c0++;
			a[++tot] = s[i]-'0';
		}
	}
	
	sort(a+1,a+tot+1,greater<int>());
	
	if(a[1] == 0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=tot;i++){
		cout<<a[i];
	}
	
	return 0;
}
