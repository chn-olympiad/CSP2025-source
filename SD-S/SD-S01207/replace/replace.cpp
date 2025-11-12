#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s[N][3];
struct node{
	string st1,st2;
	int l,r;
}a[N];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		int flag=0,start,end;
		string str1="",str2="";
		for(int j=1;j<=s[i][1].length();j++){
			
			if(s[i][1][j]==s[i][2][j]&&flag) {
				flag=0;end=j-1;
			}
			if(s[i][1][j]!=s[i][2][j]&&!flag){
				flag=1;start=j;
			}
			if(flag){
				str1+=s[i][1][j];
				str2+=s[i][2][j];
			} 
		}
		a[i].l=start;a[i].r=end;a[i].st1=str1,a[i].st2=str2;
	} 
	string instr1,instr2;
	for(int m=1;m<=q;m++){
		int ans=0;
		cin>>instr1>>instr2;
		for(int i=1;i<=n;i++){
			int tmp=a[i].r-a[i].l+1;
			//cout<<a[i].r<<' '<<a[i].l;
			for(int j=0;j<tmp;j++){
				int yes=1;
				for(int k=j;k<tmp+j;k++){
					
					//cout<<a[i].st1[k-j]<<' '<<instr1[k]<<' '<<a[i].st2[k-j]<<' '<<endl;
					
					
					if(!(a[i].st1[k-j]==instr1[k]&&a[i].st2[k-j]==instr2[k])) yes=0;
				}
				if(yes==1) ans++;
			}			
		}
		cout<<ans<<endl;
	}
	return 0;
}




		
