#include<bits/stdc++.h>
using namespace std;
string a;
int cnt=1,b[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[cnt]+=a[i]-'0';
			cnt++;
		}
	}
	sort(b+1,b+cnt);
	for(int i=cnt-1;i>=1;i--){
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

