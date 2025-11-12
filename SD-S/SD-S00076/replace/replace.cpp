#include<bits/stdc++.h>
using namespace std;
int n,q;string at,bt;
struct node{
	string as,bs;
	int abid,bbid;
}a[201000];
bool check(int l,int id,int y){
	for(int i=0;i<y;i++)if(at[i+l]!=a[id].as[i])return 0;
	return 1;
}
bool isspecial(){
	for(int i=1;i<=n;i++){
		int ab=0,bb=0;
		for(int j=0;j<a[i].as.length();j++){
			if(a[i].as[j]!='a'){
				if(a[i].as[j]=='b')ab++;
				else return 0;
			}
		}
		for(int j=0;j<a[i].bs.length();j++){
			if(a[i].bs[j]!='a'){
				if(a[i].bs[j]=='b')bb++;
				else return 0;
			}
		}
		if(ab!=1||bb!=1)return 0;
	}
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)cin>>a[i].as>>a[i].bs;
	if(isspecial()){
		for(int i=1;i<=n;i++){
			for(int j=0;j<a[i].as.length();j++){
				if(a[i].as[j]=='b'){
					a[i].abid=j;
					break;
				}
			}
			for(int j=0;j<a[i].bs.length();j++){
				if(a[i].bs[j]=='b'){
					a[i].bbid=j;
					break;
				}
			}
		}
		while(q--){
			int ans=0,atbid,btbid;
			cin>>at>>bt;
			for(int i=0;i<at.length();i++){
				if(at[i]=='b'){
					atbid=i;
					break;
				}
			}
			for(int i=0;i<bt.length();i++){
				if(bt[i]=='b'){
					btbid=i;
					break;
				}
			}
			for(int i=1;i<=n;i++)if(a[i].abid-a[i].bbid==atbid-btbid)ans++;
			printf("%d\n",ans);
		}
		return 0;
	}
	while(q--){
		int ans=0;
		cin>>at>>bt;
		for(int id=1;id<=n;id++){
			int x=at.length(),y=a[id].as.length();
			for(int l=0;l<=x-y;l++){ 
				if(check(l,id,y)==1){
					string newat="";
					for(int i=0;i<x;i++){
						if(l<=i&&i<l+y)newat+=a[id].bs[i-l];
						else newat+=at[i];
					}
					if(newat==bt)ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}//max60pts
