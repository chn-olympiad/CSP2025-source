#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200001],s2[200001],t1,t2;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)cin>>s1[i]>>s2[i];
	for(int i=0;i<q;i++){
		int sum=0;
		cin>>t1>>t2;
		int l=t1.length();
		for(int j=0;j<n;j++){
			int l1=s1[j].length();
			for(int k=0;k<=l-l1;k++){
				bool flag=true;
				for(int m=0;m<k;m++){
					if(t1[m]!=t2[m]){
						flag=false;
						break;
					}
				}
				if(flag==false)break;
				for(int m=k+l1;m<l;m++){
					if(t1[m]!=t2[m]){
						flag=false;
						break;
					}
				}
				if(flag==false)continue;
				for(int m=0;m<l1;m++){
					if(t1[k+m]!=s1[j][m]||t2[k+m]!=s2[j][m]){
						flag=false;
						break;
					}
				}
				if(flag){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
return 0;
}

