#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,q;
string s1[1086],s2[1086];
string c1,c2;
int a[100086];
void run(){
	string t1,t2;map<int,int>p;
	for(int i=1;i<=n;i++){
		cin>>c1>>c2;
		a[i]=c2.find("b")-c1.find("b");
		p[a[i]]++;
	}
	while(q--){
		cin>>t1>>t2;
		cout<<p[t2.find("b")-t1.find("b")]<<endl;
	}
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin>>n>>q;
	if(n>1000){
		run();
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	string t1,t2,t3;int m=0;
	while(q--){
		m=0;
		cin>>t3>>t2;
		for(int i=1;i<=n;i++){
			t1=t3;
			int fi=t1.find(s1[i]);
			if(fi>=t1.size())break;
			for(int j=0;j<s2[i].size();j++){
				t1[j+fi]=s2[i][j];
			}
			if(t1==t2)m++;
		}
		cout<<m<<endl;
	}
	return 0;
}