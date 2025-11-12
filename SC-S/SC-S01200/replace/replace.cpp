#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,q,ans;
string s[N][3];

void query(string a,string b){
	int len=a.size();
	for(int i=0;i<len;i++){
		string x="";
		for(int j=i;j<len;j++){
			x+=a[j];
			for(int k=1;k<=n;k++){
				if(x==s[k][1]){
					int p=2;
					for(int w=j+1;w<len;w++){
						p=1;
						if(a[w]!=b[w]){
							p=0;
							break;
						}
					}
					if(p==1){
						ans++;
					}
				}
			}
		}
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		ans=0;
		string t1,t2;
		cin>>t1>>t2;
		query(t1,t2);
		cout<<ans<<'\n';
	}
	return 0;
}
