#include<bits/stdc++.h>

using namespace std;
struct node{
	string a,b;
	
}s[200005];
vector<int> e;
int fs(string a,string b,string aa,string bb){
	e.clear();
	int cnt=0;
	int lena=a.size(),lenb=b.size();
	for(int i=0;i<lena;i++){
		if(a[i]==b[0] && lena-i>=lenb){
			bool f=1;
			for(int x=0;x<lenb;x++){
				if(a[i+x]!=b[x]){
					f=0;
					break;
				}
			}
			if(f){
				e.push_back(i);
			}
		}
	}
	for(int i=0;i<e.size();i++){
		string a1(a);
		for(int j=e[i];j<e[i]+lenb;j++){
			a1[j]=bb[j-e[i]];
		}
		if(!a1.compare(aa)){
			cnt++;
		}
	}
	return cnt;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,ans=0;
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> s[i].a >> s[i].b;
	}
	string x,y;
	int cnt;
	while(q--){
		cin >> x >> y;
		cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=fs(x,s[i].a,y,s[i].b);
		}
		cout << cnt << endl;
	}
	return 0;
}
