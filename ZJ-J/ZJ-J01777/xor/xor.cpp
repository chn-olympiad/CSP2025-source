#include<bits/stdc++.h>
using namespace std;
int a[500001];
int cnt[500001];
int ch[1<<21+1];
set<int> st;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;scanf("%d %d",&n,&k);
	for(int i=0;i<=(1<<21);i++){
		ch[i]=k^i;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cnt[i]=cnt[i-1]^a[i];
		if(a[i]==k){
			ans++;
			st.clear();
			st.insert(cnt[i]);
			continue;	
		}
		if(st.find(ch[cnt[i]])!=st.end()){
			ans++;
			st.clear();
		}
		st.insert(cnt[i]);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}