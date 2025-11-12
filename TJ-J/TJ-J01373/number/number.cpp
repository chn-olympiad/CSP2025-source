#include<bits/stdc++.h>
using namespace std;
long long n,m,nm,mn[1000000];
string s;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0' and s[i]<='9'){
			mn[nm]=s[i]-'0';
			nm++;
		}
	}
	sort(mn,mn+nm,cmp);
	for(int i=0;i<nm;i++){
		cout<<mn[i];
	}
	return 0;
} 
