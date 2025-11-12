#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	if(a<b){
		return false;
	}else{
		return true;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[110042];
	string s;
	int c=0;
	cin>>s;
	for(int i=0;i<=s.size()+1;i++){
		if('0'<=s[i]&&s[i]<='9'){
			s[i]=s[i]-'0';
			a[i]=s[i];
			c++;
		}
	}
	sort(a,a+c+10,cmp);
	for(int i=0;i<c;i++){
		cout<<a[i];
	}
	return 0;
}
