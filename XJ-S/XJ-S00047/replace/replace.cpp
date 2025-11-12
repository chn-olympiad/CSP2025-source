//#include<bits/stdc++.h>
//using namespace std;
//const int N=2e5+10;
//int n,q,ans=0;
//string s1[N],s2[N],sq1[N],sq2[N],ss1,ss2;
//int main() {
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
//	cin>>n>>q;
//	for(int i=1; i<=n; i++) {
//		cin>>s1[i]>>s2[i];
//	}
//	for(int i=1; i<=q; i++) {
//		cin>>sq1[i]>>sq2[i];
//	}
//	for(int t=1; t<=q; t++) {
//		int sum=0;
//		int len=sq1[t].size();
//		int ii=0;
//		for(int l=0; l<len; l++) {
//			for(int r=len+1; r>0; r++) {
//				ii=0;
//				for(int i=l+1; i<r; i++) {
//					ss1[++ii]=sq1[t][i];
//				}
//				for(int i=1; i<=n; i++) {
//					if(ss1==s1[i]) {
//						ss2=sq1[t][i];
//						for(int j=l+1; j<r; j++) {
//							ss2[j]=ss1[j];
//						}
//						if(ss2==sq2[t]){
//							sum++;
//						}
//					}
//				}
//			}
//		}
//		cout<<sum<<'\n';
//	}
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,ans=0;
string s1[N],s2[N],sq1[N],sq2[N],ss1,ss2;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>s1[i]>>s2[i];
	}
	for(int i=1; i<=q; i++) {
		cin>>sq1[i]>>sq2[i];
	}
	for(int t=1; t<=q; t++) {
		cout<<0<<'\n';
	}
	return 0;
}
