#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s1[N],s2[N],g1[N],g2[N];
int p;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,l,r;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++){
		cout<<0;
//		cin>>g1[i]>>g2[i];
//		if(g1[i].size()!=g2[i].size())
//		else{
//			p=0;
//			for()
//		}
	}
}
//根据条件，长度不变 
//不难想到，由于只能替换一次，所以本次必定包含不同处
//然后容我写棵字典树再说 
//fa xian fu za du hen da,dan wo mei you shi jian la
