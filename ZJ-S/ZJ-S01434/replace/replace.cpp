#include<bits/stdc++.h>
#define ll long long
using namespace std;
string rep[200010][2];
string pre[200010];
string nxt[200010];
string frm, toa;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ll n,m; scanf("%lli %lli",&n,&m);
	for(int i=0;i<n;i++){
		cin >> rep[i][0] >> rep[i][1];
		ll s = rep[i][0].size()-1;
		string str1 = rep[i][0], str2 = rep[i][1];
		ll lp=0, rp=s;
		string pr="", nx="";
		while(str1[lp]==str2[lp]&&lp<=s) pr+=str1[lp++];
		while(str1[rp]==str2[rp]&&rp>=0) nx=str1[rp--]+nx;
		string r1="", r2="";
		for(int j=lp;j<=rp;j++) r1+=str1[j],r2+=str2[j];
		rep[i][0] = r1; rep[i][1] = r2;
		pre[i] = pr; nxt[i] = nx;
	}
	for(int i=0;i<m;i++){
		ll cnt = 0;
		cin >> frm >> toa;
		if(frm.size()!=toa.size()){
			cout << "0\n";
			continue;
		}
		ll s = frm.size()-1;
		string str1 = frm, str2 = toa;
		ll lp=0, rp=s;
		string pr="", nx="";
		while(str1[lp]==str2[lp]&&lp<=s) pr+=str1[lp++];
		while(str1[rp]==str2[rp]&&rp>=0) nx=str1[rp--]+nx;
		string r1="", r2="";
		for(int j=lp;j<=rp;j++) r1+=str1[j],r2+=str2[j];
		for(int j=0;j<n;j++){
			if(!(r1==rep[j][0] && r2==rep[j][1])) continue;
			if(pr.size()<pre[j].size() || nx.size()<nxt[j].size()) continue;
			int flag = 0;
			int poi = 0, s1 = pr.size()-1, s2 = pre[j].size()-1;
			for(;s2-poi>=0;poi++){
				if(pr[s1-poi]!=pre[j][s2-poi] && pre[j].size()){
					flag = 1;
					break;
				}
			}
			s1 = nx.size()-1; s2 = nxt[j].size()-1; 
			for(poi=0;poi<=s2;poi++){
				if(nx[poi]!=nxt[j][poi] && nxt[j].size()){
					flag = 1;
					break;
				}
			}
			if(flag) continue;
			++cnt;
		}
		printf("%lli\n",cnt);
	}
	return 0;
}
