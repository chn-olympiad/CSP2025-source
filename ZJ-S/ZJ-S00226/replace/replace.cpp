#include<bits/stdc++.h>
using namespace std;
typedef pair<string,string> pss;typedef pair<int,int>pii;
struct difstrs{
	struct difstr{
	int dstart,dend,dlen;
	string dstr;
	};
	difstr strs[2];
	difstrs(int as,int ad,int al,string stra,int bs,int bd,int bl,string strb){
		strs[0].dend=ad;strs[0].dlen=al;strs[0].dstart=as;strs[0].dstr=stra;
		strs[1].dend=bd;strs[1].dlen=bl;strs[1].dstart=bs;strs[1].dstr=strb;
	}
};
difstrs diff(string sa,string sb){
	int start_d=-1;
	int end_d;
	for(int j=0;j<sa.length();j++){
		if(sa[j]!=sb[j]&&start_d==-1)start_d=j;
		if(sa[j]!=sb[j])end_d=j;
	}
	int len_d=end_d-start_d+1;
	string dstr_a="";string dstr_b="";
	for(int i=start_d;i<=end_d;i++){
		dstr_a+=sa[i];dstr_b+=sb[i];
	}
	difstrs rd(start_d,end_d,len_d,dstr_a,start_d,end_d,len_d,dstr_b);
	return rd;
}
string getij(string s,int i,int j){
	if(i<0||j>s.length())return"NAN";
	string rs="";
	for(int k=i;k<=j;k++){
		rs+=s[k];
	}
}
vector<pii> difij(string a,string b){
	vector<pii> difs;
	if(a.length()<b.length())return difs;
	for(int l=0;l<=a.length()-b.length()+1;l++){
		if(getij(a,l,l+b.length()-1)==b){
			difs.push_back({l,a.length()-l-b.length()});
		}
	}
	return difs;//first:qian;second:hou
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("replace1.in","r",stdin);
	int n,q;
	cin>>n>>q;
	vector<pss>ns(n);vector<pss>qs(q);
	for(int i=0;i<n;i++)cin>>ns[i].first>>ns[i].second;
	for(int i=0;i<q;i++)cin>>qs[i].first>>qs[i].second;
	vector<difstrs>pns;
	for(int i=0;i<n;i++){
		difstrs pn=diff(ns[i].first,ns[i].second);
		pns.push_back(pn);
	}
	vector<difstrs>qns;
	for(int i=0;i<q;i++){
		difstrs qn=diff(qs[i].first,qs[i].second);
		qns.push_back(qn);
	}
	vector<bool>diffs(n);
	for(int i=0;i<n;i++){
		bool dis=(pns[n].strs[0].dstr)==(qns[0].strs[0].dstr);
		if(dis)cout<<"Ahaa";
		cout<<"i:"<<i<<"  p:"<<pns[i].strs[0].dstr<<pns[i].strs[0].dstr.length()<<"  q:"<<qns[i].strs[0].dstr<<qns[i].strs[0].dstr.length()<<"\n";
		diffs[n]=dis;
	}
	vector<int>cnts(q);
	for(int z=0;z<q;z++){
		int cnt=0;
		for(int i=0;i<n;i++){
//			cout<<"\ni:"<<i<<"\np:"<<pns[i].strs[0].dstr<<"\nq:"<<qns[i].strs[0].dstr;
			vector<pii>dfstr1=difij(qs[z].first,ns[i].first);
			vector<pii>dfstr2=difij(qs[z].second,ns[i].second);
			if(!dfstr1.empty()&&!dfstr2.empty()){
				cnt++;
			}
		}
		cnts[z]=cnt;
	}
	for(int z=0;z<q;z++)cout<<cnts[z]<<endl;

	return 0;
}
