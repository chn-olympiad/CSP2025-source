#include <bits/stdc++.h>
using namespace std;

string s1[100005],s2[100005],t1,t2;
int n,q,cnt;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	
	for(int i=1;i<=q;i++){
		cnt=0;
		cin>>t1>>t2;
		for(int j=1;j<=n;j++)
			if(t1.find(s1[j])!=string::npos and t1.find(s1[j])==t2.find(s2[j])){
				t1.replace(t1.find(s1[j]),s1[j].size(),s2[j]);
				if(t1==t2)cnt++;	
				t1.replace(t1.find(s2[j]),s2[j].size(),s1[j]);
			}
		printf("%d\n",cnt);
	}
	return 0;
}
