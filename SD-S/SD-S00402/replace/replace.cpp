/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,d[200006],ans;
string s1[200006],s2[200006],t1,t2;
//int fun(string s){//abcdefabc
//	int l=s.length()-1;
//	for(int i=l/2;i>=1;++i){
//		int fl=0;
//		for(int j=1;j<=i;++j){
//			if(s[j]!=s[l+j-i]){
//				//cout<<'h';
//				fl=1;
//				break;
//			}
//		}
//		if(!fl)
//			return i;
//	}
//	return 0;
//}
bool check(int l,int k){
	//cout<<'f'<<l<<' '<<k<<endl;
	int r=l+s1[k].length()-1-1;
	for(int i=1;i<=n;++i){
		int c=t1[i];
		if(l<=i&&i<=r){
			//cout<<'h';
			c=s2[k][i-l+1];
		}
		if(t2[i]!=c)
			return 0;
	}
	return 1;
}
void ff(){
	int nn=t1.length()-1;
	for(int k=1;k<=n;++k){
		int l=s1[k].length()-1;
		//cout<<'q'<<l;
		for(int i=1;i<=nn-l+1;++i){
			//cout<<'y';
			int f=1;
			for(int j=i;j<=i+l-1;++j){
				if(s1[k][j-i+1]!=t1[j]){
					//cout<<'j';
					f=0;
					break;
				}
			}
			if(f){
				if(check(i,k))
					++ans;
			}
		}
	} 
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s1[i]>>s2[i];
		s1[i]=" "+s1[i],s2[i]=" "+s2[i];
		//d[i]=fun(s1[i]);
	}
	while(q--){
		ans=0;
		cin>>t1>>t2;
		t1=" "+t1,t2=" "+t2;
		ff();
		cout<<ans<<"\n";
	}
	return 0;
}

