#include<bits/stdc++.h>
using namespace std;
const int Mod=1e9+7;
const int N=2e5+10;
unsigned long long v[N],vv[N];
string s,ss;
unsigned long long Tr(string the){
	unsigned long long num=0;
	unsigned long long now=1;
	for(int i=0;i<the.size();i++){
		num=num+now*(the[i]-'a'+1)%Mod;
		num%=Mod;
		now=now*233%Mod;
	}
	return num;
}
int n,m;
int main(){
	freopen("raplace.in","r",stdin);
	freopen("") 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s;
		v[i]=Tr(s);
		cin>>s;
		vv[i]=Tr(s);
	}
	while(m--){
		cin>>s;
		cin>>ss;
		int mi=0x3f3f3f3f,ma=0;
		for(int i=0;i<s.size();i++){
			if(s[i]!=ss[i]){
				mi=min(mi,i);
				ma=max(ma,i);
			}
		}
		int Vs[N],Vss[N];
		unsigned long long num=0;
		unsigned long long now=1;
		for(int i=0;i<s.size();i++){
			num=num+now*(s[i]-'a'+1)%Mod;
			num%=Mod;
			now=now*233%Mod;
			Vs[i]=num;
		}
		num=0;
		now=1;
		for(int i=0;i<s.size();i++){
			num=num+now*(s[i]-'a'+1)%Mod;
			num%=Mod;
			now=now*233%Mod;
			Vss[i]=num;
		}
		int ct=0;
		for(int k=1;k<=n;k++){
			bool check=true;
			for(int i=0;i<=mi;i++){
				for(int j=ma;j<s.size();j++){
					if(check&&(Vs[j]+Mod-Vs[i])%Mod==v[k]&&(Vss[j]+Mod-Vss[i])%Mod==vv[k]){
						check=false;
						ct++;
					}
				}
			}
		}
		cout<<ct<<endl;
	}
	for(int i=1;i<=n;i++){
		cout<<v[i]<<endl;
	}
	return 0;
}
