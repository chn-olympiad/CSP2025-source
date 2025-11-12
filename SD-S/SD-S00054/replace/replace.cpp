#include<bits/stdc++.h>
using namespace std;
int ans,n,q,cnt = 0,u,shi;
string t1[1005000],t2[1000500],s1,s2,zi;
char z[5000500];
vector<int> lin[5000500];
vector<string> huan[5000500];
void tri(int dian,int pos,string a,string b){
	if(pos==((int)a.size())){
		huan[dian].push_back(b);
		return;
	}
	for(auto it:lin[dian]){
		if(z[it]==a[pos]){
			tri(it,pos+1,a,b);
			return;
		}
	}
	cnt++;
	lin[dian].push_back(cnt);
	z[cnt] = a[pos];
	tri(cnt,pos+1,a,b);
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	
	for(int i = 1;i<=n;i++){
		cin>>t1[i]>>t2[i];
		tri(0,0,t1[i],t2[i]);
	}

	if(q==1){
		cin>>s1>>s2;
		
	}
	while(q--){
		cin>>s1>>s2;
		if(s1==s2){
			cout<<0;
			continue;
		}
		ans = 0;
		for(int i = 0;i<(min((int)s1.size(),(int)s2.size()));i++){
			u = 0;
			for(int j = i;j<(min((int)s1.size(),(int)s2.size()));j++){
				shi = 0;
				for(auto it:lin[u]){
					if(z[it]==s1[j]){
						shi = 1;
						u = it;
						break;
					}
				}
				if(shi == 0)break;
				for(auto it:huan[u]){
					zi.clear();
					for(int k = 0;k<i;k++){
						zi+=s1[k];
					}
					zi+=it;
					for(int k = j+1;k<s1.size();k++){
						zi+=s1[k];
					}
				if(zi==s2){
					ans++;
				}
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}

