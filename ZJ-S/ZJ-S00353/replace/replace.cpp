#include<bits/stdc++.h>
using namespace std;
const int MAXN=200010;
string s1[MAXN],s2[MAXN];
bool cmp(string s1,string s2,int b1,int b2,int l){
	//cout<<"Now compare "<<s1<<" "<<s2<<":"<<endl;
	for(int i=0;i<l;i++){
		if(s1[b1+i]!=s2[b1+i]){
			//cout<<"break because of "<<i<<s1[b1+1]<<s2[b1+i]<<endl;
			return false;
		}
	}
	return true;
}
int lfind(string s1,string s2){
	int i=0,k=0;
	
	//cout<<s1.size()-s2.size()<<endl;
	while(i<=s1.size()-s2.size()){
		while(s1[i]!=s2[0]&& i<=s1.size()-s2.size()){
			i++;
		}
		//cout<<i<<endl;
		if(i<=s1.size()-s2.size()){
			if(cmp(s1,s2,i,0,s2.size()-1)){
				
				return i;
			}
			i++;
		}
		if(i>=s1.size()-s2.size())return -1;
	}
	return -1;
}
int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	//cout<<n<<q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		//cout<<s1[i]<<s2[i]<<endl;
	}
	string t1,t2;
	for(int i=0;i<q;i++){
		cin>>t1>>t2;
		int ans=0;
		//if(t1.size()!=t2.size()){
			printf("0\n");
		//	continue;
		//}
		
		/*
		for(int j=1;j<=n;j++){
			int fd1=lfind(t1,s1[j]),fd2=lfind(t2,s2[j]);
			//cout<<fd1<<" "<<fd2<<endl;
			if(fd1!=-1 && fd2!=-1 && fd2==fd1){
				//int l=s1[i].size();
				//if(cmp(t1,t2,0,0,fd1-1) && cmp(t1,t2,fd1+l,fd1+l,t1.size()-fd1-l-1)){
					ans++;
				//}
			}
			
		}
		printf("%d\n",ans);//*/
	}
	fclose(stdin);
	fclose(stdout);
	/*
	string s="cdcdcd",s1="abc";
	//18446744073709551615
	cout<<s.find(s1);*/
	return 0;
}
