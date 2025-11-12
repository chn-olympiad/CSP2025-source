#include<bits/stdc++.h>
using namespace std;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	char s[1000005],d[1000005];
	int j=0;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<sizeof(s);i++){
		if(s[i]>='0' && s[i]<='9'){
			d[j]=s[i];
			j++;
		}
	}
	sort(d,d+j,cmp);
	cout<<d;
	return 0;
}

