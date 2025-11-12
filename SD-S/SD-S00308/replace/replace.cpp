#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200005][2],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	while(q--){
		int flag1=0,flag2=0,cnt1=0,cnt2=0;
		cin>>t1>>t2;
		if(t1.size!=t2.size()){
			cout<<0;
			continue;
		}
		for(int i=0;i<t1.size();i++){
			if(t1[i]!=a&&t1.[i]!=b){
				flag1=1;
			}
			if(t2[i]!=a&&t2.[i]!=b){
				flag2=1;
			}
			if(t1[i]=='b'){
				cnt1++;
			}
			if(t2[i]=='b'){
				cnt2++;
			}
		}
		if(flag1==0&&flag2==0&&cnt1==1&&cnt2==1){
			int anss=n;
			cnt1=cnt2=0;
			for(int i=0;i<t1.size();i++){
				if(t1[i]=='a'&&flag==0){
					cnt1++;
				}
				else if(t1[i]=='b'){
					flag=1;
				}
				else{
					cnt2++;
				}
			}
			for(int i=1;i<=n;i++){
				int place;
				for(int j=1;j<a[i][1].size();j++){
					if(a[i][1][j]=='b'){
						place=j;
					}
				}
				if(place-1>cnt1||a[i][1].size-place>cnt2){
					anss--;
				}
				for(int j=1;j<a[i][2].size();j++){
					if(a[i][2][j]=='b'){
						place=j;
					}
				}
				if(place-1>cnt1||a[i][2].size-place>cnt2){
					anss--;
				}
			}
			cout<<anss;
		}
	}
	return 0;
} 
