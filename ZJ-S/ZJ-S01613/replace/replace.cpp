#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define i128 __int128
const int N=2e5+5;
struct node{
	int nq,nh,cz;
};
int n,q,ans; 
string s1[N],s2[N];
string t1[N],t2[N];
node as[N],at[N];
bool tsb(){
	int na=0,nb=0;
	for(int i=1;i<=n;i++){
		na=nb=0;
		for(int j=0;j<(int)s1[i].length();j++){
			if(s1[i][j]=='a') na++;
			else if(s1[i][j]=='b') nb++;
			else return false;
		}
		if(nb!=1) return false;
		na=nb=0;
		for(int j=0;j<(int)s2[i].length();j++){
			if(s2[i][j]=='a') na++;
			else if(s2[i][j]=='b') nb++;
			else return false;
		}
		if(nb!=1) return false;
	}
	for(int i=1;i<=q;i++){
		na=nb=0;
		for(int j=0;j<(int)t1[i].length();j++){
			if(t1[i][j]=='a') na++;
			else if(t1[i][j]=='b') nb++;
			else return false;
		}
		if(nb!=1) return false;
		na=nb=0;
		for(int j=0;j<(int)t2[i].length();j++){
			if(t2[i][j]=='a') na++;
			else if(t2[i][j]=='b') nb++;
			else return false;
		}
		if(nb!=1) return false;
	}
	return true;
}
void tsb_ycl(){
	int num1=0,num2=0;
	for(int i=1;i<=n;i++){
		num1=num2=0;
		for(int j=0;j<(int)s1[i].length();j++){
			if(s1[i][j]=='b'){
				num1=j;
				break;
			}
		}
		for(int j=0;j<(int)s2[i].length();j++){
			if(s2[i][j]=='b'){
				num2=j;
				break;
			}
		}
		as[i].nh=min(num1,num2);
		as[i].nq=(int)s1[i].length()-max(num1,num2)-1;
		as[i].cz=num1-num2;
	}
	for(int i=1;i<=q;i++){
		num1=num2=0;
		for(int j=0;j<(int)t1[i].length();j++){
			if(t1[i][j]=='b'){
				num1=j;
				break;
			}
		}
		for(int j=0;j<(int)t2[i].length();j++){
			if(t2[i][j]=='b'){
				num2=j;
				break;
			}
		}
		at[i].nh=min(num1,num2);
		at[i].nq=(int)t1[i].length()-max(num1,num2)-1;
		at[i].cz=num1-num2;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
	if(tsb()){
		tsb_ycl();
		for(int i=1;i<=q;i++){
			ans=0;
			for(int j=1;j<=n;j++){
				
				if(at[i].cz==as[j].cz&&at[i].nh>=as[j].nh&&at[i].nq>=as[j].nq){
					ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}else{
		int num1,num2,cz;
		for(int i=1;i<=q;i++){
			num1=num2=cz=-1;
			ans=0;
			cin>>t1[i]>>t2[i];
			for(int j=0;j<(int)t1[i].length();j++){
				if(t1[i][j]==t2[i][j]){
					continue;
				}
				if(num1==-1) num1=j;
				num2=j;
			}
			cz=num2-num1+1;
			for(int j=1;j<=n;j++){
				if(s1[j].length()<=t1[i].length()&&(int)s1[j].length()>=cz&&t1[i].find(s1[j])<=(t1[i].length()-1)&&t1[i].find(s1[j])==t2[i].find(s2[j])){
					ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
} 
