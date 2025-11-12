#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
long long int num[N],cnt[100],cntnum[100];
int l,ln;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[++ln]=s[i]-'0';
			cnt[num[ln]]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(cnt[i]!=0)
			for(int j=1;j<=cnt[i];j++)
				cout<<i;
	}
	return 0;
} 
