#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=114514;
char s[100000005];
int tong[11];
char res[100000005];
int ans=0;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<strlen(s);i++){
		if(s[i]>='0'&&s[i]<='9'){
			tong[((int)s[i]-48)]++;
		}
	}
	int cnt=1;
	for(int i=9;i>=0;i--){
		if(tong[i]!=0){
			for(int j=1;j<=tong[i];j++){
				res[cnt]=i+48;
				cnt++;
			}
		}
	}
	int num=1;
	for(int i=1;i<=cnt-1;i++){
		cout<<res[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
