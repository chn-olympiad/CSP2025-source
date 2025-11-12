#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,i,j,f,l,r,k,ans,b1[400010],b2[400010],len1,len2,sum;
string s,ss,sr,ssr;
struct no{
	string s1,s2;
}a[400010];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++)cin>>a[i].s1>>a[i].s2;
	while(q--){
		cin>>s>>ss;ans=0;
		for(i=1;i<=n;i++){
			sr=a[i].s1+"#"+s;ssr=a[i].s2+"#"+ss;sum=0;
			memset(b1,0,sizeof(b1));
			memset(b2,0,sizeof(b2));
			b1[0]=b2[0]=0;
			for(j=1;j<sr.size();j++){
				len1=b1[j-1];
				if(!len1||sr[j]!=sr[len1])len1=b1[len1-1];
				if(sr[j]==sr[len1])b1[j]=len1+1;
				len2=b2[j-1];
				if(!len2||ssr[j]!=ssr[len2])len2=b2[len2-1];
				if(ssr[j]==ssr[len2])b2[j]=len2+1;
				if(j>a[i].s1.size()&&b1[j]==b2[j]&&b1[j]==a[i].s1.size())sum++;
			}
			if(sum==1)ans++;
		}
		cout<<ans<<endl;
	}
}
