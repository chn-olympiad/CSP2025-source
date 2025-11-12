#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
int n,q;
string s[200010][3];
struct node{
	vector<int>v;
};
gp_hash_table<string,node>ma,mb;
int bj[200010];

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		s[i][1]=" "+s[i][1];
		s[i][2]=" "+s[i][2];
		string hv="",to="";
		int fst=0,sec=0;
		for(int j=1;j<s[i][1].size();j++){
			if(s[i][1][j]!=s[i][2][j]){
				if(!fst){
					fst=j;
					break;
				}
			}
		}
		for(int j=s[i][1].size()-1;j>=1;j--){
			if(s[i][1][j]!=s[i][2][j]){
				if(!sec){
					sec=j;
				}
			}
		}
		
		for(int j=fst;j<=sec;j++){
			hv+=s[i][1][j];
			to+=s[i][2][j];
		}
		ma[hv].v.push_back(i);
		mb[to].v.push_back(i);
//		cout<<hv<<' '<<to<<endl;
	}
//	cout<<"----"<<endl;
	for(int i=1;i<=q;i++){
		int ans=0;
		string a,b;
		cin>>a>>b;
		if(a==b){
			ans++;
		}
		a=" "+a;
		b=" "+b;
		string hv="",to="";
		int fst=0,sec=0;
		for(int j=1;j<a.size();j++){
			if(a[j]!=b[j]){
				if(!fst){
					fst=j;
					break;
				}
			}
		}
		for(int j=a.size()-1;j>=1;j--){
			if(a[j]!=b[j]){
				if(!sec){
					sec=j;
				}
			}
		}
		
		for(int j=fst;j<=sec;j++){
			hv+=a[j];
			to+=b[j];
		}
//		cout<<hv<<' '<<to<<endl;
		vector<int>va=ma[hv].v,vb=mb[to].v;
//		cout<<va.size()<<' '<<vb.size()<<endl;
		if(va.size()&&vb.size()){
			for(int j:va){
				bj[j]=1;
			}
			for(int j:vb){
				if(bj[j]){
//					cout<<j<<endl;
					//可以匹配 i，j 了
//					cout<<s[j][1].size()<<' '<<a.size()<<endl;
//for(int j=1;j<=n;j++){

					for(int p=1;p+s[j][1].size()-1<=a.size();p++){
						string na=a,nb=b;
						int pd=1;
						if(a[p+s[j][1].size()-2]!=s[j][1][s[j][1].size()-1]||b[p+s[j][1].size()-2]!=s[j][2][s[j][1].size()-1]){
							continue;
						}
//						cout<<na<<' '<<nb<<endl;
						for(int o=p,t=1;t<s[j][1].size();t++,o++){
							if(a[o]!=s[j][1][t]||b[o]!=s[j][2][t]){
								pd=0;
								break;
							}
							na[o]=s[j][2][t];
						}
//						cout<<na<<' '<<nb<<endl;
						if(pd&&na==nb){
//							if(i==102){
//								cerr<<' '<<j<<' '<<p<<endl;
//							}
							ans++;
							break;
						}
					}
						
				}
			}
			for(int j:va){
				bj[j]=0;
			}
			
		}
	cout<<ans<<'\n';
//	if(i==102){
//		cerr<<a<<endl<<endl<<b<<endl<<endl;
//		cerr<<hv<<endl<<endl<<to<<endl;
//		cerr<<ans<<endl;
//		return 0;
//	}
//	cerr<<i<<endl;
//		cout<<ans<<'\n';
	}
	return 0;
}
/*
是可以替换一次还是多次？ 
那应该是一次吧 

可以先找出 t1 和 t2 的不同，然后只需要原区间覆盖现在的 
然后相同的不能改 
所以综上，需要找到不同的区间长度相同的就行了 
看看能骗多少 

 4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

4 2
aa bb
a b
ab bb
aaa bbb
ab bb
a b


暴力可过 37375 27578 6s
 
*/