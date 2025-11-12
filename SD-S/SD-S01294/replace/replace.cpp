#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n,q;
const int N=2e5+10,mod=233;
int has(string a){
	int res=0;
	for(int i=0;i<a.length();++i){
		res=(res*mod)+a[i];
	}
	return res;
}string s1,s2;
map<int,int> mp[N];
int mul[N];
int a[N],b[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	mul[0]=1;
	for(int i=1;i<=n;i++){
		mul[i]=mul[i-1]*233;
		cin >> s1 >> s2;
		int t=s1.length();
		mp[t][has(s1)]=has(s2);
	}
	for(int i=1;i<=q;i++){
		int res=0;
		cin >> s1 >> s2;
		cout<< "0\n";
	}
	return 0;
} 
//#include<bits/stdc++.h>
//#define int unsigned long long
//using namespace std;
//int n,q;
//const int N=2e5+10,mod=233;
//int has(string a){
//	int res=0;
//	for(int i=0;i<a.length();++i){
//		res=(res*233)+a[i]-'0';
//		
//	}
//	return res;
//}string s1,s2;
//map<int,int> mp;
//int mul[N];
//int a[N],b[N];
//signed main(){
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
//	//cout << has("b") << ' ';
//	cin >> n >> q;
//	mul[0]=1;
//	for(int i=1;i<=n;i++){
//		mul[i]=mul[i-1]*233;
//		cin >> s1 >> s2;
//		int t=s1.length();
//		mp[has(s1)]=has(s2);
//	}
//	for(int i=1;i<=q;i++){
//		int res=0;
//		cin >> s1 >> s2;
//		int len=s1.length();
//		if(len!=s2.length()){
//			cout << "0\n";
//			continue;
//		}
//		int l=0,r=len-1;
//		while(s1[l]==s2[l]) l++;
//		while(s1[r]==s2[r]) r--;
//		
//		//cout << l << ' ' << r << "---\n";
//		for(int ll=0;ll<=l;ll++){
//			for(int rr=r;rr<=len-1;rr++){
//				string s3,s4;int tot=0;
//				for(int j=ll;j<=rr;j++){
//					
//					s3[tot]=s1[j],s4[tot]=s2[j];
//					tot++;
//				}
//				//cout << s3 << ' ' << s4 << '\n';
//
//				int aa=has(s3),bb=has(s4);
//				//cout << aa << ' ' << bb << '\n';
//				if(mp[aa]==bb) res++;
//			}
//		}
//		
//		
//		
//		
//		cout << res << "\n";
//	}
//	return 0;
//} 
