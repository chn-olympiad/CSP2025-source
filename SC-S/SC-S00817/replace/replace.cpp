#include<bits/stdc++.h>
using namespace std;
int n,q;
string t1,t2,t;
struct h{
	string x;
	string y;
}s[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i].x>>s[i].y;
	}
	for(int i=1;i<=q;++i){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
		}else{
			int cnt=0;
			for(int j=0;j<t1.size();++j){
				for(int y=1;y<=n;++y){
					if(t1.find(s[y].x,j)!=-1 && t1.find(s[y].x,j)==j){
						int a=t1.find(s[y].x,j);
						string b=s[y].x,tt=t1;
						tt.replace(a,b.size(),s[y].y);
						if(tt==t2){
							cnt++;
						}
					}
				}
			}
			cout<<cnt<<endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}