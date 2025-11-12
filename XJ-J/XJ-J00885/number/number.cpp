#include<bits/stdc++.h>
using namespace std;
char a[1000010];
int b[1000010],cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len1=strlen(a);
	for(int i=0;i<len1;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[cnt]=(int)a[i]-'0';
			cnt++;
		}
	}
	sort(b,b+cnt);
	if(b[cnt-1]==0){
		cout<<'0';
		return 0;
	}
	else for(int i=cnt-1;i>=0;i--)cout<<b[i];
	return 0;
} 
