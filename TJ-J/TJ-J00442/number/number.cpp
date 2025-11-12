#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int a[N];
string str1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str1;
	int ans=1;
	for(int i=0;i<=str1.size();i++){
		if(str1[i]>='0'&&str1[i]<='9'){
			a[ans]=str1[i]-'0';
			ans++;
		}
	}
	sort(a+1,a+ans+1,cmp);
	for(int i=1;i<ans;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
