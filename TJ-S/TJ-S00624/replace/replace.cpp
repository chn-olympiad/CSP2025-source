#include<bits/stdc++.h> 
using namespace std;
long long n,q,cnt;
struct ps{string a,b;}pst;
vector<ps> ec;
string str,str2,str3;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;ec.resize(n);
	for(int i = 0;i < n;i++) cin >> ec[i].a >> ec[i].b;
	for(int i = 0;i < q;i++)
	{
		cin >> str >> str3;
		for(int j = 0;j < n;j++)
		{
			pst=ec[j];
			for(int in = 0;in < str.size()+1-pst.a.size();in++)
			{
				if(str.substr(in,pst.a.size())==pst.a)
				{
					str2=str;
					for(int k=in;k<in+pst.a.size();k++) str2[k]=pst.b[k-in];
					if(str2==str3) cnt++;
				}
			}
		}
		cout << cnt << endl;
		cnt=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
