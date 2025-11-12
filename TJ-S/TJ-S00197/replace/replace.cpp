#include<iostream>
#include<cstring>
using namespace std;
string sx,sy;
int cnt=0,n,q;
string s1[100005],s2[100005];
bool check(int j,int i){
	for(int k=0;k<s1[i].size();k++){
		if(sx[j]!=s1[i][k]&&sy[j]!=s2[i][k]){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("replace.in","r",stdin); 
	freopen("replace.out","w",stdout); 
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		int ans=0;
		cin>>sx>>sy;
		sx='0'+sx;
		sy='0'+sy; 
		for(int i=1;i<min(sy.size(),sx.size());i++){
			if(s1[i]!=s2[i]&&s1[i-1]==s2[i-1])ans++;
		}
		if(ans>1)cout<<"0"<<endl;
		else{
			ans=0;
			bool flag=true;
			for(int i=1;i<=n;i++){
				flag=false;
				for(int j=1;j<sx.size();j++){
					if(sx[j]==s1[i][0]&&sy[j]==s2[i][0]){
						bool f=true;
						for(int k=0;k<s1[i].size();k++,j++){
							if(sx[j]!=s1[i][k]||sy[j]!=s2[i][k]){
								f=false;
								flag=false;
							}
							if(j==sx.size()-1&&k<s1[i].size()-1){
								f=false;
								flag=false;
								break;
							}
						}
						if(f==true)flag=true;
						if(flag==true&&sx[j]!=sy[j]){
							flag=false;
							break;
						}
						if(sx[j]!=sy[j]){
							flag=false;
							break;
						}
					}
					
				}
				if(flag==true){
					ans++;
				} 
			}
			cout<<ans<<endl;
		}
	}
	return 0; 
}
