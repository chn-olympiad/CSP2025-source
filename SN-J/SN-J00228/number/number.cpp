#include <bits/stdc++.h>

using namespace std;

string s;
int a[1000010],id;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9')
			a[++id]=s[i]-'0';
	}
	sort(a+1,a+id+1,greater<int>());
	for(int i=1;i<=id;i++)
		printf("%d",a[i]);
	return 0;
}
