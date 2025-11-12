#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,q;
string s1[maxn],s2[maxn];
string tx[maxn],ty[maxn];
int check(int l,int r,string s){
	bool flag=0;
	for(int g=0;g<n;g++){
		flag=1;
		for(int i=l;i<=r;i++){
			if(s[i]!=s1[g][i]){
				flag=0;
				break;
			}
		}
		if(flag==1){
			return g;
		}
	}
	return 0;
}
int main(){
	freopen("replace3.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=0;i<q;i++){
		cin>>tx[i]>>ty[i];
	}
	int t=0,len,ans;
	bool flag=0;
	int l,r;
	string newt;
	while(q--){
		ans=0;
		len=tx[t].size();
		string a=tx[t];
		string b=ty[t];
		for(l=0,r=len-1;l<len,r>=l;l++,r--){
			flag=1;
			for(int r=len-1;r>=l;r--){
				int ge=check(l,r,a);
				if(ge!=0){
					for(int x=0;x<l;x++){
						newt[x]=a[x];
					}
					for(int x=l;x<=r;x++){
						newt[x]=s2[ge][x];
					}
					for(int x=r+1;x<len;x++){
						newt[x]=a[x];
					}
				}
				for(int i=0;i<newt.size();i++){
					if(newt[i]!=b[i]){
						flag=0;
						break;
					}
				}	
			}
			if(flag==1){
				ans++;
			}
		}
		t++;
		cout<<ans-1<<"\n";
	}
	return 0;
}

