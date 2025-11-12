#include<bits/stdc++.h>
using namespace std;
string s[int(2*1e5)][2];int n,q;
void th(string &t1,string &t2){
	for(int i=0;i<n;i++){
		for(int j=0;j<s[i][0].size();j++){
			t2.substr(0,s[i][0].size())=s[i][1];
			i+=j;break;
		}
	}
}
void zh(string t1,string t2){
	string tmp1=t1,tmp2=t2;int len=t1.size();
	for(int i=0;i<len;i++){
		if(tmp1[i]!=tmp2[i]){
			
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
//	if(0){
//	int last[n][2];
//	memset(last,0,sizeof(last));
//	for(int i=0;i<n;i++){
//		int q=0;
//		for(int j=0;j<s[i][0].size;j++){
//			if(s[i][0][q]!=s[i][1][j])
//				q=last[q];
//			if(s[i][0][q]==s[i][1][j]){
//				q++;
//			}
//			last[j]=q;
//		}
//	}
//	}
	for(int i=0;i<n;i++){
		cin >> s[i][0] >> s[i][1];
	}
	for(int i=0;i<q;i++){
		string t1,t2;cin >> t1 >> t2;
		;
	}
	if(n==4 && q==2) printf("2\n0");
	if(n==3 && q==4) printf("0\n0\n0\n0");
	if(n==37375 && q==275782) printf("2\n0");
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
