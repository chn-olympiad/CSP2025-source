#include<iostream>
#include<string.h>
using namespace std;
long long int n,q;
int PreToB[200005];
int PreMustA[20005];
int PreMustB[20005];
string changeA[200005],changeB[200005];
string QA,QB;
string IfAB;
bool ok;
int kind;
void BaoLi()
{
	for(int i = 0; i < q; i++)
	{
		cin >> QA >> QB;
		if(QA.length() != QB.length())
		{
			cout << 0 << endl;
			continue;
		}
		kind = 0;
		for(int i = 0; i < n; i++)
		{
			if(QA.length() < changeA[i].length())
			{
				continue;
			}
			for(int j = 0; j <= QA.length() - changeA[i].length(); j++)
			{
				if(QA[j] == changeA[i][0])
				{
					ok = true;
					for(int k = 0; k < changeA[i].length(); k++)
					{
						if(changeA[i][k] != QA[j + k])
						{
							ok = false;
							break;
						}
					}
					if(ok == true)
					{
						IfAB = QA;
						for(int t = 0; t < changeA[i].length(); t++)
						{
							IfAB[j + t] = changeB[i][t];
						}
						if(IfAB == QB)
						{
							kind++;
						}
					}
				}
			}
		}
		cout << kind << endl;
	}
}
void GetB()
{
	int QTickAb,QTickBb;
	for(int i = 0; i < n; i++)
	{
		while(changeA[i][PreMustA[i]] == 'a')
		{
			PreMustA[i]++;
		}
		if(PreMustA[i] == changeA[i].length())PreMustA[i] = -1;
		while(changeB[i][PreMustB[i]] == 'a')
		{
			PreMustB[i]++;
		}
		if(PreMustB[i] == changeB[i].length())PreMustB[i] = -1;
	}
	for(int i = 0; i < q; i++)
	{
		cin >> QA >> QB;
		for(int j = 0; j < QA.length(); j++)
		{
			if(j == QA.length() - 1)QTickAb = -1;
			if(QA[j] == 'b')
			{
				QTickAb = j;
				break;
			}
		}
		for(int j = 0; j < QB.length(); j++)
		{
			if(j == QB.length() - 1)QTickBb = -1;
			if(QB[j] == 'b')
			{
				QTickBb = j;
				break;
			}
		}
		int PreNum = QTickAb - QTickBb;
		kind = 0;
		for(int j = 0; j < n; j++)
		{
			if(PreMustA[j] == -1 || PreMustB[j] == -1)continue;
			if(PreMustA[j] - PreMustB[j] == PreNum && QTickAb >= PreMustA[j] && QA.length() - QTickAb >= changeA[j].length() - PreMustA[j])
			{
				kind++;
			}
		}
		cout << kind << endl;
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 0; i < n; i++)
	{
		cin >> changeA[i] >> changeB[i];
	}
	if(q > 500 && n > 500)
	{
		ok = true;
		for(int i = 0; i < 10; i++)
		{
			if(changeA[i][0] != 'a' && changeA[i][0] != 'b')
			{
				ok = false;
			}
		}
		if(ok == true)
		{
			GetB();
		}else
		{
			BaoLi();
		}
	}else
	{
		BaoLi();
	}
	return 0;
}
