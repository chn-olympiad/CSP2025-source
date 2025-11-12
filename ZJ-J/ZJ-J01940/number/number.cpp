#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string p;
	cin>>p;
	int ws=0;
	for(int i=0;i<p.size();i++){
		if(p[i]<='9'&&p[i]>='0'){
			a[ws]=p[i]-'0';
			ws++;
		}
	}
	sort(a,a+ws);
	for(int i=ws-1;i>=0;i--) cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
