#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	int num=0;
	for(int i=0;i<len;i++){
		if(s[i]=='0'){
			a[++num]=0;
		}
		else if(s[i]=='1'){
			a[++num]=1;
		}
		else if(s[i]=='2'){
			a[++num]=2;
		}
		else if(s[i]=='3'){
			a[++num]=3;
		}
		else if(s[i]=='4'){
			a[++num]=4;
		}
		else if(s[i]=='5'){
			a[++num]=5;
		}
		else if(s[i]=='6'){
			a[++num]=6;
		}
		else if(s[i]=='7'){
			a[++num]=7;
		}
		else if(s[i]=='8'){
			a[++num]=8;
		}
		else if(s[i]=='9'){
			a[++num]=9;
		}
	}
	sort(a+1,a+num+1,cmp);
	if(a[1]==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=num;i++){
		cout<<a[i];
	}
	return 0;
}
