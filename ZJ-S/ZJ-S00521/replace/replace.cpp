#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
long long n,m,a[100000],t;
int main(){
	fast;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string s,s1;
		cin>>s>>s1;
		for(int j=0;j<s.size();j++){
			for(int k=0;k<s1.size();k++){
				if(s[j]!=s1[k]){
					a[t+1]++;
				}
			}
			t++;
		}
	}
	sort(a+1,a+5+t);
	for(int j=t-5;j>=t-4-m;j--){
		cout<<a[j]<<endl;
	}
	return 0;
}

