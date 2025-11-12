#include<bits/stdc++.h>
using namespace std;
int num[1000005];
string s;
int n,idxx=1;
bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[idxx]=s[i]-'0';
			idxx++;
		}
	}
	sort(num+1,num+idxx,cmp);
	for(int i=1;i<=idxx-1;i++){
		cout<<num[i];
	}
	return 0;
}
