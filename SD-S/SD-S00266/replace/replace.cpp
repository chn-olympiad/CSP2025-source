#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5,maxl=5e6+5;
struct f{
	string s1,s2;
}a[maxn];
int begn[maxl];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i].s1>>a[i].s2;
	while(q--){
		//25 
		string t1,t2;
		cin>>t1>>t2;
		int l1=t1.length(),l2=t2.length();
		if(l1!=l2){
			cout<<0<<endl;
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int L=a[i].s1.length();
			int tot=0;
			for(int j=0,k=0;j<l1;j++){
				if(t1[j]!=a[i].s1[k]&&k!=0){
					j--;
					k=0;
					continue;
				}
				k++;
				if(k==L) begn[++tot]=j-L+1;
			}	
//			cout<<tot<<" "<<begn[tot]<<endl;
			for(int j=1;j<=tot;j++){
				bool flag=1;
				for(int k=begn[j],p=0;k<=begn[j]+L-1;k++,p++){
					if(t2[k]!=a[i].s2[p]){
						flag=0;
						break;
					}
				}
				if(flag){
					string t3=t2;
					for(int k=begn[j],p=0;k<=begn[j]+L-1;k++,p++) t3[k]=a[i].s1[p];
					if(t3==t1) ans++;
//					cout<<t3<<endl;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
