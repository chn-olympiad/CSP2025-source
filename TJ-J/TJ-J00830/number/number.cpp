#include<bits/stdc++.h>
using namespace std;
string s;
int a[9000000];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int lens=s.size();
	int bj=1,num=0;
	for(int i=0;i<lens;i++){
		if(isdigit(s[i])){
			a[bj]=s[i]-'0';
			bj++;
			num++;
		}
	}
	sort(a+1,a+bj,cmp);
	for(int i=1;i<bj;i++){
		cout<<a[i];
	}
	return 0;
}
