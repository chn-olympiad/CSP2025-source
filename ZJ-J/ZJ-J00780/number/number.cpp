#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N];
vector<int> v;
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int l=strlen(s+1);
	for(int i=1;i<=l;i++)
		if(s[i]>='0'&&s[i]<='9')v.push_back(s[i]-'0');
	sort(v.begin(),v.end(),cmp);
	for(int i:v)putchar(i+'0');
	putchar('\n');
	return 0;
}
