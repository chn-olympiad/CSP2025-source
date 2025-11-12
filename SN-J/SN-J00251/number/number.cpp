//SN-J00251 孙悦翔 西安市曲江第一学校
#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;

int a[MAXN],x;
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++x]=s[i]-'0';
		}
	}
	sort(a,a+x+1);
	for(int i=x;i;i--){
		cout<<a[i];
	} 
	return 0;
} 
