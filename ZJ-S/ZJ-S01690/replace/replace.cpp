#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,le[N],baz=1003;
unsigned long long su[N][2];
string s[N][2];
struct Node{
	int l,r;
	unsigned long long sum1,sum2;
};
Node SC(string st[]){
	int len=st[0].length(),l=0;
	int r=len-1;
	unsigned long long s1=0,s2=0;
	for(int i=0;i<len;i++){
		if(st[0][i]==st[1][i]) l++;
		else break;
	}
	for(int i=len-1;i>=0;i--){
		if(st[0][i]==st[1][i]) r--;
		else break;
	}
	for(int i=l;i<=r;i++){
		s1=(s1*baz)+st[0][i]-'a';
		s2=(s2*baz)+st[1][i]-'a';
	}
	return {l,r,s1,s2};
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string st[2];
		cin>>st[0]>>st[1];
		Node y=SC(st);
		su[i][0]=y.sum1;su[i][1]=y.sum2;//cout<<y.l<<"&&"<<y.r<<"\n";
		for(int j=y.l;j<=y.r;j++){
			s[i][0]+=st[0][j];
			s[i][1]+=st[1][j];
		}
		le[i]=s[i][0].length();
	}
	while(q--){
		int cnt=0;
		string t[2];
		cin>>t[0]>>t[1];
		if(t[0].length()!=t[1].length()){
			cout<<0<<"\n";
			continue;
		}
		Node y=SC(t);
		int len=y.r-y.l+1;
		for(int i=1;i<=n;i++){//cout<<le[i]<<"**";
			if(le[i]!=len) continue;
			if(y.sum1==su[i][0] && y.sum2==su[i][1]) cnt++;
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
