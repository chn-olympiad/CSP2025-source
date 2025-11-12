#include<bits/stdc++.h>//ql1l2n
#define ll long long
using namespace std;
const int N=2e5+10;
int n,q;ll ans;
string s[N][2];
int rm[N][2][2];
bool check(string t){
	int b=0;
	for(int i=0;i<t.length();i++){
		if(t[i]=='b')b++;
		else if(t[i]!='a')return false;
		if(b>=2)return false;
	}
	if(b==0)return false;
	return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		f=f&&check(s[i][0])&&check(s[i][1]);
	}
	if(f){
		for(int i=1;i<=n;i++){
			for(int j=0;j<s[i][0].length();j++){
				if(s[i][0][j]=='b'){
					rm[i][0][0]=j;
					rm[i][0][1]=s[i][0].length()-(j+1);
				}
			}for(int j=0;j<s[i][1].length();j++){
				if(s[i][1][j]=='b'){
					rm[i][1][0]=j;
					rm[i][1][1]=s[i][1].length()-(j+1);
				}
			}
		//	cout<<rm[i][0][0]<<' '<<rm[i][0][1]<<' '<<rm[i][1][0]<<' '<<rm[i][1][1]<<'\n';
		}
	}
	while(q--){
		ans=0;
		string a,b;
		cin>>a>>b;
		if(a.length()!=b.length()){
			cout<<"0\n";
			continue;
		} 
		int lena=a.length();
		if(f&&check(a)&&check(b)){
			int fra=0,rea=0,frb=0,reb=0;
			for(int j=0;j<a.length();j++){
				if(a[j]=='b'){
					fra=j;
					rea=b.length()-(j+1);
				}
			}
			for(int j=0;j<b.length();j++){
				if(b[j]=='b'){
					frb=j;
					reb=b.length()-(j+1);
				}
			}
	//		cout<<fra<<' '<<rea<<' '<<frb<<' '<<reb<<'\n';
			for(int i=1;i<=n;i++){
				if(rm[i][0][0]<=fra&&rm[i][0][1]<=rea&&rm[i][1][0]<=frb&&rm[i][1][1]<=reb
				&&rm[i][0][0]-rm[i][1][0]==fra-frb){
					ans++;
				}
			}
		}else{
			for(int i=0;i<lena;i++){
				for(int j=1;j<=n;j++){
					string ta=s[j][0],tb=s[j][1];int lenb=ta.length();
					if(lenb>lena)continue;
					string st=a;
					bool f=1;
					for(int k=0;k<lenb;k++){
						st[i+k]=tb[k];
						if(a[i+k]!=ta[k]){
							f=0;
							break;
						}
					}
					if(!f)continue;
					if(st==b)ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

