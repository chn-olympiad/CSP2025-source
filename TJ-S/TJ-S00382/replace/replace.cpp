#include<bits/stdc++.h>
using namespace std;
int n,q,a[200005],t[200005];
int t1,t2;
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		for(t1=0;t1<=s1.size();t1++){
			if(s1[i]=='b')break;
		}for(t2=0;t2<=s2.size();t2++){
			if(s2[i]=='b')break;
		}
		t[i]=t2-t1;
	}
	sort(t+1,t+1+n);
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		for(t1=0;t1<=s1.size();t1++){
			if(s1[i]=='b')break;
		}for(t2=0;t2<=s2.size();t2++){
			if(s2[i]=='b')break;
		}
		for(int j=1;j<=n;j++){
			if(t[j]==t2-t1)cout<<1<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
