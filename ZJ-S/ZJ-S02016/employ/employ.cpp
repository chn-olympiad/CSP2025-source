#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int maxn=15;
void read(int& x){
	char c;
	bool f=0;
	while((c=getchar())<48) f|=(c==45);
	x=c-48;
	while((c=getchar())>47) x=x*10+c-48;
	x=(f ? -x : x);
}
int n,m;
int a[maxn],b[maxn];
string s;
bool check(){
	int p=0,cnt=0;
	for(int i=0;i<(int)s.size();i++){
		if(p>=a[b[i+1]]){
			++p;
			continue;
		}
		if(s[i]=='0') ++p;
		else ++cnt;
	}
	return cnt>=m;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n),read(m);
	cin>>s;
	for(int i=1;i<=n;i++) read(a[i]),b[i]=i;
	int ans=0;
	do{
		if(check()) ++ans;
	}while(next_permutation(b+1,b+n+1));
	printf("%d",ans);
	return 0;
}

