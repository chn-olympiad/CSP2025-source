#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
string s;
int a[1000000]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int ans=0;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[ans]=s[i];
			ans++;
		}
	}
	sort(a,a+ans,cmp);
	for(int i=0;i<ans;i++){
		cout<<a[i]-'0';
	}
	fclose(stdin);
	fclose(stdout);	 
	return 0;
}
