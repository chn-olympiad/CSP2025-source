//SN-J00337 张巍邺 西安市曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int ton[N];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int cnt=0;
	for(int i = 0;i<s.size(); i++){
		if(s[i]>='0'&&s[i]<='9'){
			ton[cnt++] = s[i]-'0';
		}
	}


	sort(ton,ton+cnt,cmp);
	
	for(int i = 0;i<cnt; i++){
		cout << ton[i];
	}
	return 0;
}
