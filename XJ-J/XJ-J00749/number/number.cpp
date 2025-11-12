#include <bits/stdc++.h>
using namespace std;
string s,n;
int a[100010],b,t[100010],cnt;

bool cmp1(int x,int y){
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	b=s.size();
	for(int i=0;i<s.size();i++){
		if(s[i]<='9' && s[i]>='0'){
			a[i]+=int(s[i])-48;
			cnt++;
		}
		else{
			continue;
		}
	}
    sort(a,a+b,cmp1);
    for(int i=0;i<cnt;i++){
    	if(a[1]==0){
    		cout<<0;
    		break;
		}
		else{
			cout<<a[i];
		}
	}
	return 0;
 }
