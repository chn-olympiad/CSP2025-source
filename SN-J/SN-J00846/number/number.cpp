/*
祁杨  SN-J00846 西安市曲江第一学校 
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e8+10;
int num = 0;
string a;
int b[N];
int cmp(int x,int y){
	return b[x]<b[y];
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int j = 0;
	for(int i = 0;i<a.size();i++){
		if(a[i]>='0' && a[i]<='9'){
			b[j] = a[i]-'0';
			j++;
		}
	}
	sort(b,b+j);
	for(int i = j-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}
