#include<bits/stdc++.h>
using namespace std;

const int N=1e4+5;
int n,q,L,R;
string t1[N],t2[N];
string s1[N],s2[N],s3[N];
int dl[N],dr[N];

bool cmp(int t1_id,int t1_begin,int s3_id){
//cout<<t1_id<<":"<<t1_begin<<" ";
	if(t1_begin+s3[s3_id].size()-1>t1[t1_id].size()-1) return false;
	if(t1_begin-1<dl[s3_id]-1) return false;
	for(int i=0;i<s3[s3_id].size();i++){//cout<<t1[t1_id][t1_begin+i];
		if(t1[t1_id][t1_begin+i]!=s3[s3_id][i]) return false;
		
	}
	return true;
}

bool check(int t1_id,int t1_begin,int s3_id){
	for(int i=0;i<dl[s3_id];i++){
		if(t1[t1_id][t1_begin-i-1]!=s2[s3_id][dl[s3_id]-1-i]||t1[t1_id][t1_begin-i-1]!=t2[t1_id][t1_begin-i-1]) return false;
	}//cout<<"!!!";
	int m=s2[s3_id].size();
	for(int i=dr[s3_id]+1;i<m;i++){
		//cout<<t1[t1_id][t1_begin+i+dr[s3_id]-dl[s3_id]];
		if(t1[t1_id][t1_begin+i-dl[s3_id]]!=s2[s3_id][i]||t1[t1_id][t1_begin+i-dl[s3_id]]!=t2[t1_id][t1_begin+i-dl[s3_id]]) return false;
	}//cout<<endl;
	return true;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	
	for(int i=1;i<=n;i++){
		cin>>t1[i]>>t2[i];
	}
	
	for(int i=1;i<=q;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		if(s1[i].size()!=s2[i].size()) continue;
		dl[i]=-1;
		for(int j=0;j<s1[i].size();j++){
			if(s1[i][j]!=s2[i][j]){
				if(dl[i]==-1) dl[i]=j;
				dr[i]=j;
			}
		}
	}
	for(int i=1;i<=q;i++){
		if(s1[i].size()!=s2[i].size()) continue;
		for(int j=0;j<s1[i].size();j++){
			if(dl[i]<=j&&j<=dr[i]) s3[i]+=s1[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		if(s1[i].size()!=s2[i].size()){
			printf("0\n");
			continue;
		}
		for(int j=1;j<=n;j++){
			for(int t=0;t<t1[j].size();t++){
				if(cmp(j,t,i)){
					if(check(j,t,i)) ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
