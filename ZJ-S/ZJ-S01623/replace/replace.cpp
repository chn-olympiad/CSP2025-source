#include<bits/stdc++.h>
#define LL long long
using namespace std;

int n,q;

int ss2,se2;

string s[222222][2];

string s0[222222][2];

pair<string,int> s_[222222];

int len00;

int ss[222222];

int se[222222];

int len_[222222];

string t[222222][2];

bool cmp(pair<string,int> a,pair<string,int> b){
	
	int lena,lenb;
	if(a.second==0) lena=ss2-se2+1;
	else lena=se[a.second]-ss[a.second]+1;
	if(b.second==0) lenb=ss2-se2+1;
	else lenb=se[b.second]-ss[b.second]+1;
	for(int i=1;i<=min(lena,lenb);i++){
		
		if(a.first[i]<b.first[i]) return 1;
		if(a.first[i]>b.first[i]) return 0;
		
		
	}
	if(lena!=lenb) return lena<lenb;
	return a.second < b.second;
}

int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin >> n >> q;
	
	for(int i=1;i<=n;i++){
		
		s0[i][1]=s0[i][2]=s_[i].first=" ";
		
		s_[i].second=i;
		
		cin >> s[i][1] >> s[i][2];
		
		s[i][1]=' '+s[i][1];
		
		s[i][2]=' '+s[i][2];
		
		if(s[i][1]==s[i][2]){
			
			ss[i]=-1;
			continue;
			
		}
		
		int len=s[i][1].size()-1;
		
		len_[i]=len;
		
		ss[i]=1;
		
		for(int j=1;s[i][1][j]==s[i][2][j];j++) ss[i]=j+1;
		
		se[i]=len;
		
		for(int j=len;s[i][1][j]==s[i][2][j];j--) se[i]=j-1;
		
		for(int j=ss[i],k=1;j<=se[i];j++,k++){
			
			s_[i].first[k]=s[i][1][j];
			s0[i][1][k]=s[i][1][j];
			s0[i][2][k]=s[i][2][j];
//			cout << s_[i].first[k];
			
		}
//		cout << "\n";
	}

	
	sort(s_+1,s_+n+1,cmp);
	
	
	while(q--){
		
		int ans=0;
		
		string t1,t2,t1_,t2_;
		
		cin >> t1 >> t2;
		
		t1=' '+t1;
		
		t2=' '+t2;
		
		len00=t1.size()-1;
		
		ss2=1;
		
		for(int j=1;t1[j]==t2[j];j++) ss2=j+1;
		
		se2=len00;
		
		for(int j=len00;t1[j]==t2[j];j--) se2=j-1;
		
		t1_=t2_=" ";
		
		for(int j=ss2,k=1;j<=se2;j++,k++){
			
			t1_[k]=t1[j];
			t2_[k]=t2[j];
		}
		int si=upper_bound(s_+1,s_+n+1,make_pair(t1_,0),cmp)-s_;
		while(si<=n){
			s0[s_[si].second][1]==t1_ && s0[s_[si].second][2]==t2_;
			
			if(se[s_[si].second]-se2!=ss[s_[si].second]-ss2) break;
			
			bool flag=0;
			
			for(int i=ss2,j=ss[s_[si].second];i<=se2;i++,j++){
				
				if(s[s_[si].second][1][j]!=t1[i]){
					
					
					flag=1;
					
					break;	
					
				}
				
				
			}
			
			if(flag) break;
			
			
			si++;
			
			
			flag=0;
			
			if(ss[s_[si-1].second] > ss2) continue;
			if(len_[s_[si-1].second]-se[s_[si-1].second] > len00-se2) continue;
			
			for(int i=1,j=ss2-ss[s_[si-1].second]+1;i<=len_[s_[si-1].second];i++,j++){
				
				if(s[s_[si-1].second][1][i]!=t1[j]
				|| s[s_[si-1].second][2][i]!=t2[j]){
					
					flag=1;
					
					break;
					
				}
				
			}
			
			if(flag==0) ans++;
			
		}
		
		cout << ans << '\n';
		
	}
	
	
}
