#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string str;
int s[505], p[505];
long long ans=1, j, n, m;
bool cmp(int a, int b){
	return a>b;
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	cin>>str;
	for(int i=1; i<=n; i++){
		if(str[i-1]-'0')s[i]=s[i-1];
		else s[i]=s[i-1]+1;
	}for(int i=0; i<n; i++){
		scanf("%d", &p[i]);
	}sort(p, p+n, cmp);
	for(int i=n-1; i>=0; i--){
		if(str[i]-'0'==0)continue;
		for(; j<n; j++){
			if(p[j]<=s[i]){
				break;
			}
		}ans*=(j-(n-1-i))+(n-m?1:0);
		m++;
	}printf("%lld", ans%998244353);
}