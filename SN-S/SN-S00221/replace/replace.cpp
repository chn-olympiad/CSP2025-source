#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
unsigned long long p=13331,pc[5000005];
int n,q;
unsigned long long hshf[5000005],hshs[5000005];
string tf,ts;
struct node{
	string s1,s2;
	unsigned long long hsh1,hsh2;
}e[MAXN];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>q;
	pc[0]=1;
	for(int i=1;i<=5000000;i++){
		pc[i]=pc[i-1]*p;
	}
	for(int i=1;i<=n;i++){
		cin>>e[i].s1>>e[i].s2;
		for(int j=0;j<e[i].s1.size();j++){
			e[i].hsh1=e[i].hsh1*p+e[i].s1[j];
		}
		for(int j=0;j<e[i].s2.size();j++){
			e[i].hsh2=e[i].hsh2*p+e[i].s2[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>tf>>ts;
		int len1=tf.size(),len2=ts.size(),st=0;
		for(int j=0;j<len1&&j<len2;j++){
			if(j<len1) hshf[j+1]=hshf[j]*p+tf[j];			
			if(j<len2) hshs[j+1]=hshs[j]*p+ts[j];
			if(j<len1&&j<len2&&!st) st=j+1;
		}
		int cnt=0;
		for(int k=1;k<=n;k++){
			int l1=e[k].s1.size(),l2=e[k].s2.size();
			if(len2-len1!=(int)e[k].s2.size()-(int)e[k].s1.size()||e[k].s1.size()>len1)
				continue;
//			cout<<e[k].hsh1<<" "<<e[k].hsh2<<":\n";
			for(int j=1;j<=len1-e[k].s1.size()+1;j++){
				
//				cout<<j<<" "<<hshf[j+l1-1]-hshf[j-1]*pc[l1]<<" "<<&hshs[j+l2-1]-hshs[j-1]*pc[l2]<<"\n";
				if(hshf[j+l1-1]-hshf[j-1]*pc[l1]==e[k].hsh1&&hshs[j+l2-1]-hshs[j-1]*pc[l2]==e[k].hsh2&&hshf[len1]-hshf[j+l1-1]*pc[len1-j+1-l1]==hshs[len2]-hshs[j+l2-1]*pc[len2-j+1-l2])
					cnt++;
				if(hshf[j]!=hshs[j]) break;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
