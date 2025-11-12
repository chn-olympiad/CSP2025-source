#include<bits/stdc++.h>
using namespace std; 
string t1,t2,t3,t4,zr;int fi,la,n,q;
vector<int> fd[30];
struct e{
	string s1,s2;
}s[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].s1>>s[i].s2;
		fd[s[i].s1[0]-'a'+1].push_back(i);
	}
	for(int j=1;j<=q;j++){
		cin>>t1>>t2;
		int f=1,ans=0;
		t3=zr,t4=zr;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		else {
			for(int i=0;i<t1.size();i++){
				if(t1[i]!=t2[i]){
					if(f)fi=i;
					la=i;
					f=0;
				}
			}
			int now=-1;
			for(int i=fi;i<=la;i++){
				t3+=t1[i];
				t4+=t2[i];
			}
			int dis=t3[0]-'a'+1;
			for(int i=0;i<fd[dis].size();i++){
				if(s[fd[dis][i]].s1==t3&&s[fd[dis][i]].s2==t4)ans++;
			}
			while(fi>=1){
				fi--;
			    t3=t1[fi]+t3;
			    t4=t2[fi]+t4;
			    dis=t3[0]-'a'+1;
			    for(int i=0;i<fd[dis].size();i++){
				    if(s[fd[dis][i]].s1==t3&&s[fd[dis][i]].s2==t4)ans++;
			    }
			}
			while(la<t1.size()){
				la++;
				t3+=t1[la];
				t4+=t2[la];
			    dis=t3[0]-'a'+1;
				for(int i=0;i<fd[dis].size();i++){
				    if(s[fd[dis][i]].s1==t3&&s[fd[dis][i]].s2==t4)ans++;
			    }
			}
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
