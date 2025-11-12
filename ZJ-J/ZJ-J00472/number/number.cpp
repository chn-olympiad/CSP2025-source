#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000010];
long long x;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	x=1;
	for(long long i=0;i<s.size();i++){
		if('0'<=s[i] && s[i]<='9'){
			a[x]=s[i]-'0';
			x++;
		}		
	}
	sort(a+1,a+x,cmp);
	for(long long i=1;i<=x-1;i++)	cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
