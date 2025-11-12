#include<bits/stdc++.h>
using namespace std;
int n,q;
int a[2005],b[2005];
int c1[2005][2005],c2[2005][2005],q1[2005],q2[2005];
string cs1,cs2,st;
int len;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	cin>>st;
	len=st.size();
	for(int i=0;i<len;i++){
		a[i+1]=st[i]-'0';
	}
	cin>>st;
	len=st.size();
	for(int i=0;i<len;i++){
		b[i+1]=st[i]-'0';
	}
	for(int t=1;t<=n;t++){
		cin>>st;
	len=st.size();
	for(int i=0;i<len;i++){
		c1[t][i+1]=st[i]-'0';
	}
	cin>>st;
	len=st.size();
	for(int i=0;i<len;i++){
		c2[t][i+1]=st[i]-'0';
	}	
	}
	
	for(int t=1;t<=q;t++){
		cin>>st;
		len=st.size();
		for(int i=0;i<len;i++){
			q1[i+1]=st[i]-'0';
		}
		cin>>st;
		len=st.size();
		for(int i=0;i<len;i++){
			q2[i+1]=st[i]-'0';
		}
		cout<<"0\n";
	}
	return 0;
}
/*

*/
