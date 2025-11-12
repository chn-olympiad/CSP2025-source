#include <bits/stdc++.h>
using namespace std;
int n,q,cnt;
string s[200005][2];
char a[200005][100][2];
string d[200005][2];
char b[200005][100][2]={' '};
queue<int>qq;
queue<int>ff;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		int f=0,l=0,cnt=0;
		for(int j=0;j<s[i][1].length();j++){
			if(s[i][1][j]!=s[i][2][j]){
				a[i][l][1]=s[i][1][j];
				a[i][l][2]=s[i][2][j];
				l++;
				f=1;
			}if(f==1&&s[i][1][j]==s[i][2][j]){
				a[i][l][1]=' ';
				a[i][l][2]=' ';
				l++;
			}
			//cout<<a[i][l][1]<<"    "<<a[i][l][2]<<"\n";
		}
	}
	for(int i=1;i<=q;i++){
		cin>>d[i][1]>>d[i][2];
		for(int j=0;j<d[i][1].length();j++){
			if(d[i][1][j]!=d[i][2][j]){
				b[i][j][1]=d[i][1][j];
				b[i][j][2]=d[i][2][j];
			}
		}		
		for(int k=1;k<=n;k++){
			int f=0,ff=0,l=0;
			for(int j=0;j<d[i][1].length();j++){
				if(f==0&&b[i][j][1]!=b[i][j][2]){
					f=1;
				}
				if(f==1){
					if(a[k][l][1]==b[i][j][1]&&a[k][l][2]==b[i][j][2]){
						l++;
					}else{
						ff=1;
						break;
					}
				}
			}
			if(ff==0)cnt++;
		}
        cout<<cnt+1<<endl;
	}
	return 0;
}
