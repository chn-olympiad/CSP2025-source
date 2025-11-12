#include<bits/stdc++.h>
using namespace std;

char s[100010],a[100010];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=strlen(s);
	long long m=1;
	long long cnt=0;
	for(long long i=0;i<len;i++){
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'
		||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
			a[m]=s[i];
			cnt++;
			m++;
		}
	}
	sort(a+1,a+cnt+1);
	for(long long i=cnt;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}

