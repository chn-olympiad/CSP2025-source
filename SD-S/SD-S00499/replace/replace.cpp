#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=1e4+5,L=2005;
int n,q;//next[N][L],
string t[N][2];
vector <int> f;
vector <int> next[N];
void kmp1(string s,int x){
//	cout<<x<<endl;
	next[x][1]=0;
	for(int i=2,j=0;i<s.size();i++){
		while(j&&s[i]!=s[j+1]) j=next[x][j];
		if(s[i]==s[j+1]) j++;
		next[x][i]=j;
//		cout<<i<<" "<<j<<endl;
	}
}
void kmp2(string s,int x){
//	cout<<endl<<x<<endl;
	for(int i=1,j=0;i<s.size();i++){
		while(j&&s[i]!=t[x][0][j+1]) j=next[x][j];
		if(s[i]==t[x][0][j+1]) j++;
//		cout<<i<<" "<<j<<endl;
		if(j==(t[x][0].size()-1)){
//			cout<<i<<" ";
			f.push_back(i);
			j=next[x][j];
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

//	string s1=" aba",s2=" abababaa";
//	cout<<(s1-s2)<<endl;
	cin>>n>>q;
	if(n<=10005){
		for(int i=1;i<=n;i++){
			cin>>t[i][0]>>t[i][1];
			t[i][0]=" "+t[i][0];
			next[i].resize(t[i][0].size());
			kmp1(t[i][0],i);
		}
		string s1,s2;
		for(int i=1;i<=q;i++){
		//	cout<<"%"<<i<<endl;
			ll ans=0;
			cin>>s1>>s2;
			s1=" "+s1;
			for(int j=1;j<=n;j++){
				f.resize(0);
				kmp2(s1,j);
				for(int k=0;k<f.size();k++){
					int z=f[k],y=z-t[j][0].size()+2;
		//				cout<<y<<" "<<z<<endl;
					bool flag=1;
					for(int l=1;l<s1.size();l++){
						char c1=s1[l],c2=s2[l-1];
						if(l>=y&&l<=z) c1=t[j][1][l-y];
		//					cout<<c1<<" "<<c2<<endl;
						if(c1!=c2) {
							flag=0;
							break;
						}
					}
					if(flag) ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	else{
		for(int i=1;i<=q;i++) cout<<0<<endl;
	}
	/*
	t[1][0]=s1;
	kmp1(s1,1);
	kmp2(s2,1);
	*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
