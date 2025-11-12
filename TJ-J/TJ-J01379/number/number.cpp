#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[100010];
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[i]=s[i]-'0';
		}else{
			a[i]=-1;
		}
	}sort(a,a+len,cmp);
	for(int i=0;i<len;i++){
		if(a[i]==-1){
			break;
		}
		cout<<a[i];
		
	}
	return 0;
} 
