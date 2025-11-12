#include<bits/stdc++.h>
#include<string>
using namespace std;
string s;
int a[1000009];
int as;
int maxn=-1;
int c=9;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		maxn=-1;
		for(int j=0;j<=s.size()-1;j++){
			if(s[j]>='0'&&s[j]<='9'){
				a[j]=s[j];
				as++;
			}	
		}
	}
	for(int i=0;i<=as;i++){
		cout<<a[i];
	}
}
//我还会回来的！！！ 
