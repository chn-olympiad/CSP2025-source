#include<bits/stdc++.h>
using namespace std;
string s;
int a[100005],h=1;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[h]=s[i]-48;
			h++;
		}
	}
	sort(a+1,h+a+1,cmp);
	for(int i=1;i<h;i++){
		cout<<a[i];
	}
	return 0;
} 
