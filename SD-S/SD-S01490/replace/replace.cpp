#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q,t=0;
	string s1[1000][2],s2[2];
	int l[4];
	int r[4],len1,len2;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1[i][0]>>s1[i][1];
	}
	cin>>s2[0]>>s2[1];
	len2=s2[0].length();
	for(int i=0;i<len2;i++){
		if(s2[0][i]=='b'){
			l[0]=i;
			r[0]=len2-i-1;
			cout<<l[0]<<r[0];
		}
		if(s2[1][i]=='b'){
			l[1]=i;
			r[1]=len2-i-1;
		}
	}
	for(int i=0;i<n;i++){
		len1=s1[i][0].length();
		for(int j=0;j<len1;j++){
			if(s1[i][0][j]=='b'){
				l[3]=j;
				r[3]=len1-j-1;
			}
			if(s1[i][1][j]=='b'){
				l[4]=j;
				r[4]=len1-j-1;
			}
		}
		if((l[1]-l[0])==(l[4]-l[3])&&(l[3]<=l[0])&&(l[4]<=l[1])&&(r[3]<=r[0])&&(r[4]<=r[1])){
			t++;
			cout<<i<<endl;
		}
	}
	cout<<t;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
