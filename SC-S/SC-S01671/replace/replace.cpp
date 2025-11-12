#include <bits/stdc++.h>
using namespace std;
string str1[200005],strq1[200005],str2[200005],strq2[200005],strl;
int n,q;
int main() { 
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	cin >>n>>q;
	for(int i=1;i<=n;i++){
		cin >>str1[i]>>str2[i];
	}
	for(int i=1;i<=q;i++){
		cin >>strq1[i]>>strq2[i];
	}
	for(int i=1;i<=q;i++){//问题 
	int cnt=0;
		for(int j=1;j<=n;j++){//替换 
			strl=strq1[i];
			int idx=strq1[i].find(str1[j]),len=str1[j].size();
			if(idx!=-1){
				strl.replace(idx,len,str2[j]);
				if(strl==strq2[i]) cnt++;
			}
		}
		cout <<cnt<<endl; 
	}
	
	return 0;
}