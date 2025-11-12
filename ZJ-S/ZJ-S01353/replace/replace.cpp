#include<bits/stdc++.h>
using namespace std;
struct node{
	int p[270];
}trie[1000010];
int n,m,shou[200010],wei[200010],cn,l[7000000];
string s[200010][3],t[200010][3];
int pu(char a,char b){
	return 26*(a-'a')+b-'a';
}
void read(int u,int o){
	char c=' ';
	while(c<'a'||c>'z'){
		c=getchar();
	}
	while(c>='a'&&c<='z'){
		s[u][o]+=c;
		c=getchar();
	}
}
void rea(int u,int o){
	char c=' ';
	bool f=0;
	int g(0);
	while(c<'a'||c>'z'){
		c=getchar();
	}
	while(c>='a'&&c<='z'){
		if(o==2&&!f&&c==t[u][1][g]){
			++shou[u];
		}
		else{
			f=1;
		}
		t[u][o]+=c;
		c=getchar();
		++g;
	}
//	shou[u]=max(shou[u]-1,0);
}
void add(string a,string b){
	int z=a.size(),qi=0;
	for(int i=0;i<z;i++){
		if(!trie[qi].p[pu(a[i],b[i])]){
			cn++;
			trie[qi].p[pu(a[i],b[i])]=cn;
//			trie[cn].l=0;
		}
		qi=trie[qi].p[pu(a[i],b[i])];
	}
//	cout<<qi<<" "<<l[qi]<<"!";
	l[qi]++;
//	cout<<l[qi]<<"\n";
}
int main(){
//	cout<<"sd";
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
//	cout<<"sda";
	for(int i=1;i<=n;++i){
		read(i,1);
		read(i,2);
		add(s[i][1],s[i][2]);
	}
//	cout<<s[1][2];
//	cout<<trie[0].p[1];
	for(int i=1;i<=m;++i){
		rea(i,1);
		rea(i,2);
		int g(t[i][1].size()-1),z(g);
		while(g>=0){
			if(t[i][1][g]!=t[i][2][g]){
				break;
			}
			--g;
		}
		wei[i]=g;
		long long ans=0;
//		cout<<shou[i]<<" "<<wei[i]<<endl;
		for(int j=0;j<shou[i];++j){
			int pi=0;
			for(int k=j;k<=z&&(pi||k==j);k++){
//				cout<<t[i][1][k]<<" "<<t[i][2][k]<<"|";
				pi=trie[pi].p[pu(t[i][1][k],t[i][2][k])];
				if(k>=wei[i]){
//					cout<<t[i][1][k]<<l[pi]<<" ";
//					if(trie[pi].l){
//					}
					ans+=l[pi];
				}
			}
//			cout<<endl;
		}
//		cout<<endl;
//		if(ans){
//			cout<<t[i][1][k];
//		}
//		cout<<t[i][1]<<" "<<t[i][2]<<" ";
		printf("%lld\n",ans);
	}
	
	return 0;
}
//rp=pow(114514,1919810)!;