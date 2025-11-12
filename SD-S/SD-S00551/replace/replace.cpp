#include<bits/stdc++.h>
using namespace std;
long long n,q,ans;
string s1[200005],s2[200005],t1,t2;
bool flag;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(long long i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	for(long long i=1;i<=q;i++){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<"\n";
			continue;
		}
		for(long long j=1;j<=n;j++){
			long long id1=t1.find(s1[j],0);
			long long id2=t2.find(s2[j],0);
			if(id1==-1||id2==-1)
				continue;
			while(id1!=id2&&id1!=-1&&id2!=-1){
				if(id1<id2)
					id1=t1.find(s1[j],id1+1);
				else
					id2=t2.find(s2[j],id2+1);
			}
			flag=0;
			if(id1>=0&&id2>=0&&id1==id2){
				for(long long p=0;p<=id1-1;p++)
					if(t1[p]!=t2[p]){
						flag=1;
						break;
					}
				if(flag)
					continue;
				for(long long p=id1+s1[j].size();p<t1.size();p++)
					if(t1[p]!=t2[p]){
						flag=1;
						break;
					}
				if(flag)
					continue;
				ans++;
			}
		}
		cout<<ans<<"\n";
		ans=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
