#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3+10;
const int M = 2*N;
struct ch{
	string s1;
	string s2; 
}a[N],r[N];
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%lld%lld",&n,&q);
	for(int i = 1;i<=n;i++){
		cin>>r[i].s1>>r[i].s2;
	}
	for(int i = 1;i<=q;i++){
		cin>>a[i].s1>>a[i].s2;
	}
//	cout<<a[1].s.size()<<endl;
//	cout<<endl;
	for(int i =1;i<=q;i++){//第i对字符串 
		int ans = 0;
		for(int j = 0;j<=a[i].s1.size()-1;j++){//匹配第j位有没有首字母相同可替换字符串 
			for(int k = 1;k<=n;k++){//第k个替换对 
				bool f = 1;
				string a1 = a[i].s1;
				for(int noww = 0;noww<r[k].s1.size();noww++){//做替换 
					if(a[i].s1[j+noww]!=r[k].s1[noww]){
						break;
						f = 0;
					}
					a1[j+noww]=r[k].s2[noww];
				}
//				cout<<i<<" "<<j<<" "<<k<<" "<<a1<<"   "<<a[i].s2<<endl;
				if(f){
					if(a1==a[i].s2){
						ans++;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
} 
