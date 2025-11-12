#include<bits/stdc++.h>
using namespace std;
int cnt=0;
bool cmp(int a,int b) {
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	char lst[1000005];
	for(int i=0;i<s.length();i++){
		char v=s[i];
		if(v-'0' <= 9){
			lst[cnt++]=v;
		}
	}
	sort(lst,lst+cnt,cmp);
	for(int i=0;i<cnt;i++){

		cout<<lst[i];
		
	}
	return 0;
}
