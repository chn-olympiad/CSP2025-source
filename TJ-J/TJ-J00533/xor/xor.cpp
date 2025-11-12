#include<bits/stdc++.h>
using namespace std;

int n,k,t,sum,value,ans=-1;
vector<int> R;
int        s[500005];
bool visited[500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    sum=0;
    for(int i=0;i<n;i++){
    	cin>>value;
    	R.push_back(value);
	}
	for(int i=0;i<n;i++){
		if(i==0){
			s[0]=R[0];
	    }else{
	    	s[i]=s[i-1]^R[i];
		}
	int boole=-1;
	}//记录前缀和，f[l,r]=s[r]^s[l-1] 
	//就到这里了 ,不指望三题拿分 
	cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
