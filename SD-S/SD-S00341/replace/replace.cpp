//10pts?
#include<iostream>
#include<vector>
#include<map>
#include<stdio.h>
using namespace std;
int n,q;
string s1[200000],s2[200000],q1,q2;
vector< pair<int,int> > t[2000000];
bool flagB=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
		if(s1[i].length()>2000)flagB=1;
	}
	for(int i=0;i<q;i++){
		cin>>q1>>q2;
		int ans=0;
		for(int j=0;j<n;j++){
			int t1=q1.find(s1[j]),t2=q2.find(s2[j]);
			if(t1==t2&&t1!=-1){
				string t=q1;
				bool flag=1;
				for(int i=0;i<t.length();i++){
					if(i>=t1&&i<t1+s1[j].length()) continue;
					if(t[i]!=q2[i]) flag=0;
				}
				ans+=flag;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

