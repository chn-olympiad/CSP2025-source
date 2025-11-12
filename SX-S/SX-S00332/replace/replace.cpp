#include<bits/stdc++.h>
using namespace std;
struct node{
	string s1,s2;
	int sa1,sa2;
}a[400005];
struct Node{
	string s1,s2;
	int sa1,sa2;
}b[400005];
int n,q;
bool f[1000005],f1[1000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
		int l3=a[i].s1.size();
		int l4=a[i].s2.size();
		for(int j=0;j<l3;j++){
			if(a[i].s1[j]=='a'){
				a[i].sa1++;
			}
			if(a[i].s1[j]=='b'){
				break;
			}
		}
		for(int j=0;j<l4;j++){
			if(a[i].s2[j]=='a'){
				a[i].sa2++;
			}
			if(a[i].s2[j]=='b'){
				break;
			}
		}
//		cout<<abs(a[i].sa2-a[i].sa1)<<endl;
	}
	for(int i=1;i<=q;i++){
		memset(f,0,sizeof f);
		memset(f1,0,sizeof f1);
		int ans=0;
		cin>>b[i].s1>>b[i].s2;
//		int s1a=0,s2a=0;
		int l1=b[i].s1.size();
		int l2=b[i].s2.size();
		for(int j=0;j<l1;j++){
			if(b[i].s1[j]=='a'){
				b[i].sa1++;
			}
			if(b[i].s1[j]=='b'){
				break;
			}
		}
		for(int j=0;j<l2;j++){
			if(b[i].s2[j]=='a'){
				b[i].sa2++;
			}
			if(b[i].s2[j]=='b'){
				break;
			}
		}
//		cout<<b[i].sa1-b[i].sa2<<endl;
		for(int k=1;k<=n;k++){
			if(b[i].sa1-b[i].sa2>0&&b[i].sa1-a[k].sa1>0){
				if(f[b[i].sa1-a[k].sa1]==0){
				if(b[i].sa1-a[k].sa1==b[i].sa2-a[k].sa2){
					ans++;
					f[b[i].sa1-a[k].sa1]=1;
					}
				}
			}
		}
		for(int k=1;k<=n;k++){
			if(b[i].sa1-b[i].sa2>0&&b[i].sa1-a[k].sa2>0){
				if(f[b[i].sa1-a[k].sa2]==0){
				if(b[i].sa1-a[k].sa2==b[i].sa2-a[k].sa1){
					ans++;
					f[b[i].sa1-a[k].sa2]=1;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
