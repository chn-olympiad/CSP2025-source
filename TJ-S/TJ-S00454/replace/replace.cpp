#include<bits/stdc++.h>
using namespace std;
int n,q,l[200009],r[200009],len[200009];
string s1[200009],s2[200009],t1,t2;
bool check(int x,int y){
	string b1=t1,b2=t2;
	for(int i=x;i<=x+len[y]-1;i++){
		if(b1[i]==s1[y][i]){
			b1[i]=s2[y][i];
		}else{
			return 0;
		}
	}
	if(b1==b2)return 1;
	else return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
if(n<=100&&q<=100){
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		len[i]=s1[i].size();
		s1[i]=' '+s1[i];
		s2[i]=' '+s2[i];
	}	
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>t1>>t2;
		t1=' '+t1;
		t2=' '+t2;
		int l,r;
		for(l=1;;l++){
			if(t1[l]!=t2[l])break;
		}
		for(r=t1.size();;r--){
			if(t1[r]!=t2[r])break;
		}
		for(int j=1;j<=n;j++){
			if(len[j]<r-l+1)continue;
			for(int k=1;k<=t1.size()-len[j]+1;k++){
				if(check(k,j))ans++;
			}
		}
		cout<<ans<<endl;
	}
}else{
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		int pos1,pos2;
		for(pos1=0;pos1<n;pos1++){
			if(s1[i][pos1]=='b')break;
		}
		for(pos2=s1[i].size()-1;pos2>=0;pos2--){
			if(s2[i][pos2]=='b')break;
		}
		l[i]=pos1;
		r[i]=pos2;
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>t1>>t2;
		int pos1,pos2;
		for(pos1=0;pos1<t1.size();pos1++){
			if(t1[pos1]=='b')break;
		}
		for(pos2=t1.size()-1;pos2>=0;pos2--){
			if(t2[pos2]=='b')break;
		}
		for(int j=1;j<=n;j++){
			if(r[j]-l[j]==pos2-pos1&&l[j]<=pos1&&s1[j].size()-l[j]<=t1.size()-pos1&&r[j]<=pos2&&s2[j].size()-r[j]<=t2.size()-pos2){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
}
return 0;}
