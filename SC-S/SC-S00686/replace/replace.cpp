#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int INF=2e6+10;

long long Pow[INF]={1},hs1[INF],hs2[INF],l[INF],qwe[INF],qwr[INF];
string s1[INF],s2[INF];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	if (n>=100000&&q>=100000){
		for (int i=1;i<=q;i++)cout<<0<<"\n";
		return 0;
	}
	for (int i=1;i<=1000000;i++)Pow[i]=Pow[i-1]*131;
	for (int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];	
		int len=s1[i].length();
		long long cnt=0;
		for (int j=0;j<len;j++)cnt=(cnt+s1[i][j]-'0')*131;
		hs1[i]=cnt,l[i]=len;
		cnt=0;
		for (int j=0;j<len;j++)cnt=(cnt+s2[i][j]-'0')*131;
		hs2[i]=cnt;
	//	cout<<hs1[i]<<" "<<hs2[i]<<"\n";
	}
//	cout<<endl;
	for (int i=1;i<=q;i++){
		string t1,t2;cin>>t1>>t2;
		int len1=t1.length(),len2=t2.length();
		for (int j=0;j<len1;j++)qwe[j+1]=(qwe[j]+t1[j]-'0')*131/*,cout<<qwe[j+1]<<" "*/;
	//	cout<<endl;
		for (int j=0;j<len2;j++)qwr[j+1]=(qwr[j]+t2[j]-'0')*131/*,cout<<qwr[j+1]<<" "*/;
		int cnt=0;
		for (int j=1;j<=n;j++){
			bool flag1=0;
			for (int p=l[j];p<=len1;p++){
				long long tmp1=qwe[p]-qwe[p-l[j]]*Pow[l[j]];
				long long tmp2=qwr[p]-qwr[p-l[j]]*Pow[l[j]];
			//	long long tmp=qwe[p]/Pow[p-l[j]];
				if (tmp1==hs1[j]&&tmp2==hs2[j]){
					string tt2=t1;
					int f=0;
					for (int d=p-l[j];d<p;d++){
						tt2[d]=s2[j][f];
						f++;
					}
					if (tt2==t2)flag1=1;
				}
				if (flag1)break;
			}
//			for (int p=l[j];p<=len2;p++){
//			//	long long tmp=qwr[p]/Pow[p-l[j]];
//				if (tmp==hs[j])flag2=1;
//				if (flag2)break;
//			}
			if (flag1)/*cout<<j<<" ",*/cnt++;
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
