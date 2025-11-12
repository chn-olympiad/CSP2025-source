#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
vector<vector<string> >s1(N+1,vector<string>(3));
vector<vector<bool> >b1(30,vector<bool>(N+1));
ll n,q;
ll ans=0;
string add(string s,string a,int b){
	for(int i=0;i<=a.size()-2;i++){
		s[b+i]=a[b+i];
	}
	return s;
}
void d(string t1,string t2)
{
	int b23=1;
	for(int i=0;i<=t1.size()-1;i++){
		if(t1[i]!=t2[i]){
			b23=0;
			break;
		}
	}
	if(b23)ans++;
	for(int i=0;i<=t1.size()-1;i++){
		for(int j=1;j<=n;j++){
			if(b1[t1[i]][j]){
				bool b111=1;
				for(int k=0;k<=s1[j][1].size()-1;k++){
					if(t1[i+k]!=s1[j][1][k])b111=0;
				}
				if(b111)d(add(t1,s1[j][2],i),t2);
			}
		}
	}
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){ 
		cin>>s1[i][1]>>s1[i][2];
		b1[s1[i][1][0]][i]=1;
	}
	string t1,t2;
	while(q--){
		ans=0;
		cin>>t1>>t2;
		d(t1,t2);
		cout<<ans<<"\n";
	}
	return 0;
}
/*
18:24 完了，暴力没调完。
*/
 
/*
总结：
A题(club)可能有部分分；
B题(road)暴力都不会； 
C题(replace)暴力没调完； 
D题(employ)特殊性质A应该能过； 
应该不会爆零了。
2025.11.1
*/

