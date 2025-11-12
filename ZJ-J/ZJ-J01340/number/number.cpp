#include <iostream>
#include <cstring>
using namespace std;
const int MAXN=1e6+1;
string s;
int a[MAXN],num;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++num]=s[i]-'0';
		}
	}for(int i=1;i<=num;i++){
		int maxn=-MAXN,maxi=0;
		for(int j=1;j<=num;j++){
			if(maxn<a[j]){
				maxn=a[j],maxi=j;
			}
		}a[maxi]=0;cout<<maxn;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}