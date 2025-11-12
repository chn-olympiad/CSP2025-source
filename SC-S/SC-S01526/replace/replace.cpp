#include<bits/stdc++.h>
using namespace std;
const int N=2e5+16;
int n,q;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		s1[i]="";
		s2[i]="";
		string ts1,ts2;
		cin>>ts1>>ts2;
		int l=0,r=ts1.size()-1;
		bool flg1=true,flg2=true;
		while(flg1||flg2){
			if(ts1[l]==ts2[l]){
				l++;
			}else flg1=false;
			if(ts1[r]==ts2[r]){
				r--;
			}else flg2=false;
		}
		for(int j=l;j<=r;j++){
			s1[i]+=ts1[j];
			s2[i]+=ts2[j];
		}
	}
	for(int _=1;_<=q;_++){
		string ts1,ts2,fs1="",fs2="";
		cin>>ts1>>ts2;
		int l=0,r=ts1.size()-1;
		bool flg1=true,flg2=true;
		while(flg1||flg2){
			if(ts1[l]==ts2[l]){
				l++;
			}else flg1=false;
			if(ts1[r]==ts2[r]){
				r--;
			}else flg2=false;
		}
		for(int j=l;j<=r;j++){
			fs1+=ts1[j];
			fs2+=ts2[j];
		}
		int ans=0;
		for(int i=0;i<n;i++){
			if(s1[i]==fs1&&s2[i]==fs2){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 