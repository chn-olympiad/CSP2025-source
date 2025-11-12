//Code Originally Designed by Zhang Aoyi, SN-S00256, NOI CSP-J/S 2025, Shaanxi Province
//Lang: C++, Time: 14:30~18:30, NPU Chang'an Campus
//Xi'an Aerospace City No.1 (Junior) High School
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
using namespace std;
//priority_queue<int>q;
//priority_queue<int,vector<int>,greater<int> >q;
string s[200086][3];
string t1m,t2;
int n,q;
bool Flag=1;
//void chkSpA(){
//	int cntB1=0,cntB2=0,locB1,locB2;
//	for(int i=1;i<=n;i++){
//		int sizs=s[i][1].size();
//		for(int j=0;j<=sizs;j++){
//			if(s[i][1][j]!='a'||s[i][1][j]!='b'||cntB1>=2) return;
//			if(s[i][1][j]=='b') cntB1++;
//			if(s[i][1][j]=='b') locB1=j;
//			
//			if(s[i][2][j]!='a'||s[i][2][j]!='b'||cntB2>=2) return;
//			if(s[i][2][j]=='b') cntB2++;
//			if(s[i][2][j]=='b') locB2=j;
//		}
//	}
//}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		cin>>t1m>>t2;
		int len1=t1m.size(),len2=t2.size();
		if(len1!=len2){
			cout<<0<<"\n"; continue;
		}
		int ans=0;
		for(int i=0;i<len1;i++){
			for(int j=1;j<=n;j++){
				string t1=t1m;
				bool flag=0;
				int sj1len=s[j][1].size();
				//cout<<j<<" "<<sj1len<<"\n";
				for(int l=0;l<sj1len;l++){
					if((s[j][1][l]!=t1[i+l])||(s[j][2][l]!=t2[i+l])){
						flag=1; break;
					}
				}
				if(flag==1) continue;
				
				for(int l=0;l<sj1len;l++){
					t1[i+l]=s[j][2][l];
				}
				
				if(t1==t2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}


