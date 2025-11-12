#include<bits/stdc++.h>
using namespace std;
string s;
int m=0;
int a[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int x=s[i]-'0';
			a[++m]=x;
		}
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
