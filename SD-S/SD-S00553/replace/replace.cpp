#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;
const int N=2e5+10;
const int L=5e6+10;
int n,q,l1,l2,ans;
string s1,s2;
string t1,t2,t3,o1,o2;
int lent[L][2];
vector<string> s[2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		s[0].push_back(s1);
		s[1].push_back(s2);
	}
//	for(int i=0;i<n;i++){
//		string o1=s[0][i];
//		cout<<o1<<"\n";
//	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		t3=t1;
		//cout<<"t3 "<<t3<<"\n";
		ans=0;
		l1=t1.size();
		l2=t2.size();
		if(l1!=l2){
			printf("0\n");
			continue;
		}
		for(int j=0;j<l1;j++){
			//cout<<"t1 "<<t1<<endl;
			for(int k=0;k<n;k++){
				o1=s[0][k];
				o2=s[1][k];
				int leno1=s[0][k].size();
				//printf("j %d k %d leno1 %d\n",j,k,leno1);
				//printf("j %d lent %d\n",j,j+leno1-1);
				//cout<<o1<<" "<<o2<<"\n";
				if(j+leno1-1>l1) continue;
				bool flag=0;
				for(int l=j;l<=j+leno1-1;l++){
					//printf("l %d t1 %c o1 %c t2 %c o2 %c\n",l,t1[l],o1[l-j],t2[l],o2[l-j]);
					if(t1[l]==o1[l-j]){
						t1[l]=o2[l-j];
					}else{
						flag=1;
						break;
					}
				}
				
				if(flag){
					t1=t3;
					continue;
				} 
				for(int l=0;l<l1;l++){
					if(t1[l]!=t2[l]){
						flag=1;
						break;
					}
				}
				t1=t3;
				if(!flag) ans++;//printf("ans %d\n",ans);
			}
		}
		printf("%d\n",ans);	
	}
	return 0;
}
