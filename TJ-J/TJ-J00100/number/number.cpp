#include<bits/stdc++.h>
using namespace std;
string s;
char l;
long long n[1000005],p=1,x=0;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		l=s[i];
		if(l>='0'&&l<='9'){
			n[p]=l-'0';
			p++;
			x++;
		}
 }
	sort(n+1,n+1+x,cmp);
	for(long long i=1;i<=x;i++){
		cout<<n[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
