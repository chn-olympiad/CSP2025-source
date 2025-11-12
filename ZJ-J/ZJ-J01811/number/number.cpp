#include<bits/stdc++.h>
using namespace std;
string st;
int a[1000005],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>st;
	int s=st.size();
	for(int i=0;i<s;i++){
		if(st[i]>='0'&&st[i]<='9'){
			a[++cnt]=st[i]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>0;i--)
		cout<<a[i];
	return 0;
}
