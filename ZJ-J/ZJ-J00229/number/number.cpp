#include <bits/stdc++.h>
using namespace std;
string a;
int b[1000010],le_,cnt_;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>a;
	le_=a.size();
	for(int i=0;i<le_;++i){
		if(a[i]>='0'&&a[i]<='9') b[++cnt_]=a[i]-'0';
	}
	sort(b+1,b+cnt_+1);
	for(int i=cnt_;i;--i) cout<<b[i];
	return 0;
}
