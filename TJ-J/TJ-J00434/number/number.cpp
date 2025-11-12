#include<bits/stdc++.h>
using namespace std;
string s;
int a = 1;
int num[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n = s.size();
	for(int i = 0;i < n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[a] = s[i]-'0';
			a += 1;
		}
	}
	sort(num+1,num+a,cmp);
	for(int i = 1;i < a;i++){
		cout<<num[i];
	}
	cout<<"\n";
	return 0;
}
