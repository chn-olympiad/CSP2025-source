#include<bits/stdc++.h>
using namespace std;
const int mx=1e6+10;
int sb[mx];
string sa;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>sa;
	int len=0;
	for(int i=0;i<sa.length();i++){
		if(sa[i]>='0'&&sa[i]<='9'){
			sb[++len]=sa[i]-'0';
		}
	}
	sort(sb+1,sb+len+1);
	for(int i=len;i>=1;i--)printf("%d",sb[i]);
	return 0;
}