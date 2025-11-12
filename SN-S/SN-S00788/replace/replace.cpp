#include<bits/stdc++.h>
const int N=200005;
using namespace std;
int n,q,ans=0;
string a[N][3],s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	    cin>>a[i][1]>>a[i][2];
	while(q--){
		int l,r;ans=0;
		cin>>s1>>s2;
		for(int i=0;i<s1.length();i++)
		    if(s1[i]!=s2[i]){
		    	l=i;break;
			}
		for(int i=s1.length()-1;i>=0;i--)
		    if(s1[i]!=s2[i]){
		    	r=i;break;
			}
		string s3=s1.substr(l,r-l);
		for(int i=1;i<=n;i++){
			bool tmp=0,tmp1=0,tmp2=0;
			if(a[i][1].length()>=s3.length()){
			    for(int j=0;j<=s1.length()-a[i][1].length();j++)
			        if(s1.substr(j,a[i][1].length())==a[i][1]){
			    	    tmp=1; break;
				    }
			    if(tmp==1){
				    for(int j=0;j<=a[i][1].length()-s3.length();j++)
				         if(a[i][1].substr(j,s3.length())==s3){
				    	    tmp1=1; break;
					    }
				    if(tmp1==1){
				        for(int j=0;j<=s2.length()-a[i][2].length();j++)
				            if(s2.substr(j,a[i][2].length())==a[i][2]){
				    	        tmp2=1; break;
					    }
					    if(tmp2==1) ans+=1;
				    }
			    }
		    }
		}
		cout<<ans<<endl;
	}
	return 0;
}
