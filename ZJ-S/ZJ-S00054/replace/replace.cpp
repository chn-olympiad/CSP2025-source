#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;

int n,q,pos[maxn][2];
string s[maxn][2];

void get_diff(string &a,string &b){
	int st=-1,ed=-1;
	for (int i=0;i<(int)a.size();i++){
		if (a[i]!=b[i]){
			if (st==-1)	st=i;
			ed=i;
		}
	}
	if (st==-1){
		a="";
		b="";
	}else{
		a=a.substr(st,ed-st+1);
		b=b.substr(st,ed-st+1);
	}
}

int cal(string a,string b){
	int res=0;
	for (int i=1;i<=n;i++){
		string x=s[i][0],y=s[i][1];
		get_diff(x,y);
		if (a==x && b==y){
			res++;
		}
	}
	return res;
}

void get_b(string a,string b,int &pos_a,int &pos_b){
	for (int i=0;i<(int)a.size();i++){
		if (a[i]=='b'){
			pos_a=i;
		}
		if (b[i]=='b'){
			pos_b=i;
		}
	}
}

void init_pos(){
	for (int i=1;i<=n;i++){
		get_b(s[i][0],s[i][1],pos[i][0],pos[i][1]);
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	if ((n<=100 && q<=100) || q==1){
		string a,b;
		while (q--){
			cin>>a>>b;
			get_diff(a,b);
			cout<<cal(a,b)<<"\n";
		}
	}else{
		init_pos();
		string a,b;
		while (q--){
			cin>>a>>b;
			int x,y,res=0;
			get_b(a,b,x,y);
			for (int i=1;i<=n;i++){
				if (x-y==pos[i][0]-pos[i][1]){
					res++;
				}
			}
			cout<<res<<"\n";
		}
	}
	return 0;
}
