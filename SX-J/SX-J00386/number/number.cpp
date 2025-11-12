#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+10;
int a[maxn];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    cin>>s;
	long long len=s.size();
    int t=1;
    for(int i=0;i<len;i++){
    	if(s[i]>='0'&&s[i]<='9'){
    		a[t]=s[i]-'0';
    		t++;
		}
	}
	sort(a+1,a+1+t,cmp);
	for(int i=1;i<t;i++){
		printf("%d",a[i]);
	}
	return 0;
}