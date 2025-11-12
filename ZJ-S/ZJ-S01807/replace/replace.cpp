#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
bool flag=1;
string s1,s2,t1,t2;
map<int,int>m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        int p1,p2;
        for(int i=0;i<s1.size();i++){
        	if(s1[i]=='b')p1=i;
        	if(s1[i]!='a'&&s1[i]!='b')flag=0;
		}
        for(int i=0;i<s2.size();i++)if(s2[i]=='b')p2=i;
        m[p1-p2]++;
    }
    for(int i=1;i<=q;i++){
        cin>>t1>>t2;
        int p1,p2;
        for(int i=0;i<t1.size();i++)if(t1[i]=='b')p1=i;
        for(int i=0;i<t2.size();i++)if(t2[i]=='b')p2=i;
        if(flag)cout<<m[p1-p2]<<'\n';
        else cout<<"0\n";
    }
	return 0;
}
//freopen
