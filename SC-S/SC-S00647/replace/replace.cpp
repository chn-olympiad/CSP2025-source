#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e6+5;
int n,q;
string s1,s2;
char ss1[N],ss2[N];
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(q--){
		scanf("%s",ss1);
		scanf("%s",ss2);
		int cnt=0,flag=0,l=-1,r=-1;
		int l1=strlen(ss1);
		int l2=strlen(ss2);
		string st1,st2;
		if(l1!=l2){
			printf("0\n");
			continue;
		}
		for(int i=0;i<l1;i++){
			if(ss1[i]!=ss2[i]){
				if(l==-1)	l=i;
				r=i;
				if(flag==-1){
					printf("0\n");
					continue;
				}
				st1+=ss1[i];
				st2+=ss2[i];
				flag=1;
			}else {
				if(flag)	flag=-1;
			}
		}
		string st11,st22;
		for(int i=l;i>=0;i--){
			st11=st1;
			st22=st2;
			for(int j=l-1;j>=i;j--){
				st11=ss1[j]+st11;
				st22=ss2[j]+st22;
			}
			for(int j=r;j<l1;j++){
				if(j!=r){
					st11+=ss1[j];
					st22+=ss2[j];
				}	
				if(mp[st11]==st22)	cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}