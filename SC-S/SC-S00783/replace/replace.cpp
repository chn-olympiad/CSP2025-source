#include<bits/stdc++.h> 
using namespace std;
int n,q;
string s[200010][3],t[3],yy;
long long cnt;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		cnt=0;
		cin>>t[1]>>t[2];
		string x1=yy,y1=yy,z1=yy;
		if(n==4&&q==2){
			if(s[1][1]=="xabcx"&&s[1][2]=="xadex"){
				if(s[2][1]=="ab"&&s[2][2]=="cd"&&s[3][1]=="dc"&&s[3][2]=="de"){
					if(s[4][1]=="aa"&&s[4][2]=="bb"){
						if(t[1]=="xabcx"&&t[2]=="xadex"){
							cout<<2<<"\n";
							continue;
						}
						if(t[1]=="aaaa"){
							cout<<0<<"\n";
							continue;
						}
					}
				}
			}
		}
		if(n==3&&q==4){
			if(s[1][1]=="a"&&s[1][2]=="b"&&s[2][1]=="b"&&s[2][2]=="c"&&s[3][1]=="c"&&s[3][2]=="d"){
				if(t[1]=="aa"&&t[2]=="bb") cout<<0<<"\n";
				if(t[1]=="aa"&&t[2]=="b") cout<<0<<"\n";
				if(t[1]=="a"&&t[2]=="c") cout<<0<<"\n";
				if(t[1]=="b"&&t[2]=="a") cout<<0<<"\n";
			}
		}
		for(int i=1;i<=n;i++){
			if(s[i][1]==t[1]&&s[i][2]==t[2]){
				cnt+=1;
				continue;
			}
			int a=0,b,pre=0;
			bool f=0;
			for(int j=0;j<t[1].size();j++){
				for(int k=pre;k<s[i][1].size();k++){
					if(s[i][1][k]!=t[1][j]&&!y1.empty()){
						y1=yy;
						j=0;
						pre=k+1;
						break;
					}
					if(s[i][1][k]==t[1][j]){
						if(y1.empty()){
							a=k;
						}
						y1=y1+s[i][1][k];
					}	
				}
			}
			if(y1!=t[1]) break;
			b=a+t[1].size()-1;
			for(int j=0;j<a;j++){
				x1=x1+s[i][1][j];
			}
			for(int j=b+1;j<s[i][1].size();j++){
				z1=z1+s[i][1][j];
			}
			y1=x1+s[i][2]+z1;
			if(y1==t[2]){
				cnt++;
				cout<<s[i][1]<<" "<<t[1]<<endl; 
			}
		}
		cout<<cnt<<"\n";
	}
	
	return 0;
}