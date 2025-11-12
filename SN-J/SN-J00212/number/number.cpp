#include <bits/stdc++.h>
using namespace std;

//思路：先输入，然后处理数据，把数据存入一个数组中，把数组顺序输出即可
//请注意数据范围和sort
//rp++!!!

bool cmp(int a,int b) {
	return a > b;
}

const int N = 10000005;
int a[N];
string A;

int char_to_int(char w) {
	if(w<='9' && w >= '0'){
		return w - '0';
	}
	else{
		return 'a';
	}
}

int wo; 
int n;

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>A;
	//注意字符串从0开始 
	for(int i = 0;i<(int)A.size();i++){
		wo = char_to_int(A[i]);
		if(wo <= 9 && wo >= 0){
			n++;
			a[n] = wo;
			//cout<<wo<<" ";
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i = 1;i<=n;i++){
		printf("%d",a[i]);
	}
	return 0;
}
