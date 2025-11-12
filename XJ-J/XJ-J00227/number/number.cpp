#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int maxn,len,a[N],cnt;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<=len-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			a[cnt]=int(s[i]);
			
		}
	}
	
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<a[i]-48;
	}
	return 0;
}
