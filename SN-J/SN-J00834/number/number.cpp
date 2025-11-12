#include<bits/stdc++.h>
using namespace std;
int x[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a;
	cin>>a;
	int cnt=0;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0' and a[i]<='9'){
			x[++cnt]=a[i]-'0';
		}
	}
	sort(x+1,x+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<x[i];
	}
	return 0;
}
