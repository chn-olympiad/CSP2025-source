#include<bits/stdc++.h>
using namespace std;
string s;
int v[100010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int k=1;
	int len=0;
	int flag=s.length();
	int d=0;
	for(int i=0;i<flag;i++){
		if(s[i]>='0'&&s[i]<='9'){
			v[k++]=s[i]-'0';
			len++;
			if(s[i]-'0'!=0) d=1;
		}
	}
	sort(v+1,v+len+1,cmp);
	for(int i=1;i<=len;i++){
		cout<<v[i];
	}
	return 0;
}
