//SN-J00661 樊仕博 华阴市城关初级中学 
#include<bits/stdc++.h>
using namespace std;

char s[5000001];
int a[5000001];
int cnt;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			cnt++;
			a[cnt]=s[i]-'0';
		}else if(s[i]=='1'){
			cnt++;
			a[cnt]=s[i]-'0';
		}else if(s[i]=='2'){
			cnt++;
			a[cnt]=s[i]-'0';
		}else if(s[i]=='3'){
			cnt++;
			a[cnt]=s[i]-'0';
		}else if(s[i]=='4'){
			cnt++;
			a[cnt]=s[i]-'0';
		}else if(s[i]=='5'){
			cnt++;
			a[cnt]=s[i]-'0';
		}else if(s[i]=='6'){
			cnt++;
			a[cnt]=s[i]-'0';
		}else if(s[i]=='7'){
			cnt++;
			a[cnt]=s[i]-'0';
		}else if(s[i]=='8'){
			cnt++;
			a[cnt]=s[i]-'0';
		}else if(s[i]=='9'){
			cnt++;
			a[cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--){
		printf("%d",a[i]);
	}
	return 0;
}
