#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,q,start,end,cnt,idx;
string s[N][9],t1,t2,tm1[N],tm2[N];
int len[N];
bool sign;
int main(){
	freopen(replace.in,"r",stdin);
	freopen(replace.out,"w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		len[i]=s[i][1].size();
	}
	while(q--){
		cin>>t1>>t2;
		cnt=0;
		idx++;
		sign=false;
		if(t1.size()!=t2.size()) cout<<'0'<<endl;
		else{
			for(int i=0;i<t1.size();i++){
				if(t1[i]!=t2[i]&&!sign){
					start=i;
					sign=true;
				}
				if(t1[i]!=t2[i]&&sign){
					end=i;
				}
			}
			for(int i=start;i<=end;i++){
				tm1[idx]+=t1[i];
				tm2[idx]+=t2[i];
			}
			for(int i=1;i<=n;i++){
				if(s[i][1]==t1&&s[i][2]==t2) cnt++;
			}
			for(int i=1;i<=n;i++){
				if(len[i]!=tm1[idx].size()) continue;
				if(s[i][1]==tm1[idx]&&s[i][2]==tm2[idx]) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
