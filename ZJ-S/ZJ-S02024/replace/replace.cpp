#include<bits/stdc++.h>
using namespace std;
string s1,s2,q1,q2;
long long t,n,q,l,r,a1[100100],len[1001000],a2[100100],a3[100100],vis[100100],dp[201][101][101],maxn;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","r",stdout);	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		l=-1,r=-1;
		for(int j=0;j<s1.size();j++){
			if(s1[j]=='b'||s2[j]=='b'){
				if(l==-1)l=i;
				else{
					r=i;
					len[r-l]++;
					break;
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>q1>>q2;l=r=-1;
		for(int j=0;j<q1.size();j++){
			if(q1[j]=='b'||q2[j]=='b'){
				if(l==-1)l=i;
				else{
					r=i;
					cout<<len[r-l];
					break;
				}
			}
		}
	}
return 0;
}
//6 0 5
//5 0 0
//4 0 0
//3 0 0
//abaaa
//aabaa
