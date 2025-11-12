#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
string s;
int num[N];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	int x=0;
	for (int i=0;i<s.size();i++){
		if (s[i]>='0' && s[i]<='9'){
			num[x++]=s[i]-'0';
		}
	}
	
	sort(num,num+x,cmp);
	for (int i=0;i<x;i++){
		cout<<num[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
