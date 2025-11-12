#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int MAXL=5e6+5;
vector<pair<string,string> > diction(N);

int bucket[2*MAXL];
int special(string s){
	int L=s.size();
	int anum=0,bnum=0,bidx=-1;
	for(int j=0;j<L;j++){
		if(s[j]=='a')
			anum++;
		if(s[j]=='b'){
			bnum++;
			bidx=j;
		}
	}
	if(anum==L-1&&bnum==1)
		return bidx;
	else
		return -1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	bool is_special=true;
	
	for(int i=1;i<=n;i++){
		cin>>diction[i].first>>diction[i].second;
		int idx1=special(diction[i].first);
		int idx2=special(diction[i].second);
		if(idx1==-1||idx2==-1)
			is_special=false;
		else
			bucket[MAXL+idx1-idx2]++;
	}
	
	
	for(int qi=1;qi<=q;qi++){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<"\n";
			continue;
		}
		int T=t1.size();
		int idx1=special(t1);
		int idx2=special(t2);
		if(idx1!=-1&&idx2!=-1&&is_special){
			cout<<bucket[MAXL+idx1-idx2]<<"\n";
			continue;
		}
		string t0=t1;
		int res=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<T;j++){
				int L=diction[i].first.size();
				bool could=true;
				for(int k=0;k<L;k++)
					if(t1[j+k]!=diction[i].first[k]){
						could=false;
						break;
					}
				if(could){
					for(int k=0;k<L;k++)
						t0[j+k]=diction[i].second[k];
					if(t0==t2)
						res++;
					t0=t1;
				}
			}
		}
		cout<<res<<"\n";
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
