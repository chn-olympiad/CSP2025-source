#include<bits/stdc++.h>
using namespace std;
string s;
long long cnt=0,a[1000100];
int cmp(int a,int b){
	if(a>b){
		return 1;
	}
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=int(s[i])-48;
			cnt++;
		}
	}
	sort(a,a+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
	return 0;
}

