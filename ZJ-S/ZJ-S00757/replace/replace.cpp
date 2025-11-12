#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s[N],t[N];
string a,b,da,db;
int cl[N],l,r,dl;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
		cl[i]=s[i].size();
	}
	while(q--){
		cin>>a>>b;
		if(a.size()!=b.size()){
			printf("%d\n",0);
			continue;
		}
		l=0,r=a.size()-1;
		for(;l<=r;l++)
			if(a[l]!=b[l])
				break;
		for(;r>=l;r--)
			if(a[r]!=b[r])
				break;
		da=a.substr(l,r-l+1),db=b.substr(l,r-l+1);
		dl=da.size();
		int ans=0;
		for(int i=1;i<=n;i++){
			int a_start_to_change=a.find(s[i]),b_start_to_change=b.find(t[i]);
			int change_in_s=s[i].find(da),change_in_t=t[i].find(db);
			if(cl[i]<dl||a_start_to_change==-1||b_start_to_change==-1||change_in_s==-1||change_in_t==-1||a_start_to_change!=b_start_to_change||change_in_s!=change_in_t)
				continue;
			string q=a;
			if(q.replace(a_start_to_change,cl[i],t[i])==b)
				ans++;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
