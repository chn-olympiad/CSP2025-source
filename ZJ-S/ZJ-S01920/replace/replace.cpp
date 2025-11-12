#include <bits/stdc++.h>
using namespace std;
string s[200010][3];
struct nde{
	map<int,int>nxt;
	int fal,dep,sum;
	nde(){
		fal=0;sum=0;nxt.clear();
	}
}tre[8000010];int cnn=1;
void add(string s1,string s2){
	int nw=1;
	for(int i=0;i<s1.size();i++){
		int val=(s1[i]-'a'+1)*27+(s2[i]-'a'+1);
		if(tre[nw].nxt.count(val)==0){
			cnn++;
			tre[nw].nxt[val]=cnn;
			tre[cnn].dep=tre[nw].dep+1;
		}
		int nx=tre[nw].nxt[val],ptr=nw;
		while(ptr!=1&&tre[tre[ptr].fal].nxt.count(val)==0){
			ptr=tre[ptr].fal;
		}
		if(tre[tre[ptr].fal].nxt.count(val)==0)tre[nx].fal=1;
		else{
			tre[nx].fal=tre[tre[ptr].fal].nxt[val];
		}
		nw=nx;
	}
	tre[nw].sum++;
}
int solve(string t1,string t2,int sps,int lfp,int rgp){
//	cout<<lfp<<" "<<rgp<<endl;
	int nw=1,nwl=sps,nwr=sps,ret=0;
	for(int i=sps;i<t1.size();i++){
		int val=(t1[i]-'a'+1)*27+(t2[i]-'a'+1);
		if(tre[nw].nxt.count(val)==0)break;
		int nx=tre[nw].nxt[val];
		nw=nx;
		nwr++;
		if(nwl<=lfp&&rgp<=nwr)ret+=tre[nw].sum;
	}
	return ret;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		add(s[i][1],s[i][2]);
	}
	while(q--){
		string tj1,tj2;
		cin>>tj1>>tj2;
//		cout<<tj1.size()<<endl;
		if(tj1.size()!=tj2.size()){
			printf("0\n");
			continue;
		}
		int lf=0,rg=tj1.size();
		while(tj1[lf]==tj2[lf])lf++;
		while(tj1[rg]==tj2[rg])rg--;
		int ans=0;
		for(int i=0;i<tj1.size();i++){
			ans+=solve(tj1,tj2,i,lf,rg);
		}
		printf("%d\n",ans);
	}
	return 0;
}
