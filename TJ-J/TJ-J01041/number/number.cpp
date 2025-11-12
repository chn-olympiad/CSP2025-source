#include<bits/stdc++.h>
using namespace std;
string s;
int b[1000005];
int cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int c=s.size();
	for(int i=0;i<c;i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[cnt++]=s[i]-'0';
		}
	}
	sort(b,b+cnt);
	for(int i=cnt-1;i>=0;i--){
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
