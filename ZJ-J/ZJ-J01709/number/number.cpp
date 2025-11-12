#include<bits/stdc++.h>
using namespace std;
string s;
long long n,f[101];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();cout.tie();
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			f[s[i]-'0']++;
			//if(f[s[i]-'0']==1)k++;
		}
	}
	for(int i=9;i>=0;i--){
		if(f[i]==0)continue;
		while(f[i]--)cout<<i;
	}
	return 0;
}
