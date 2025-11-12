#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
const int MOD=998244353;
int n,k;
string s;
int a[N];
int t[N];
int s[N];
int ans=1;
bool cmp(int a,int b){
	return a>b;
}
int main (){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i],t[a[i]]++;
	for(int i=1;i<=n;i++) s[i]=s[i-1]+t[i];
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++) ans=(ans*(s[a[i]]-i+1))%MOD;
	cout<<ans;
    fclose(stdin);
	fclose(stdout);
	return 0;
}

