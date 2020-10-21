#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;
const ll MOD = 1e9 + 7;

ll binaryExpo(ll x, ll n)
{
	if(n == 0)
		return 1;
	if(n % 2 == 0)
		return binaryExpo((x*x) % MOD, n/2);
	return (x*binaryExpo((x*x) % MOD, n/2)) % MOD;
}

void solve(void)
{
	string s1, s2;
	cin >> s1 >> s2;
	ll l = s1.length();
	string aux1, aux2;
	ll in = -1, fin = l + 1;
	if(s1[0] == s2[0])
		in = 0;
	for(int i = 0; s1[i] == s2[i] && i < l; i++)
		fin = i;
	if(in >= 0)
	{
		s1.erase(in, fin + 1);
		s2.erase(in, fin + 1);
	}
	l = s1.length();
	in = -1;	fin = l + 1;
	if(s1[l - 1] == s2[l - 1])
		fin = l - 1;
	for(int i = l - 1; s1[i] == s2[i] && i >= 0; i--)
		in = i;

	if(fin != l + 1)
	{
		if(s1.size())
			s1.erase(in, fin);
		if(s2.size())
			s2.erase(in, fin);
	}
	// cout << s1 << endl;
	// cout << s2 << endl;

	l = s1.length();
	ll count = 0, sum = 0;
	ll mn = l;
	vector <ll> v;
	for(int i = 0; i < l; i++)
	{
		while(i < l && s1[i] == s2[i])
		{
			count++;
			i++;
		}
		if(count)
			v.pb(count);
		count = 0;
	}
	sort(v.rbegin(), v.rend());
	sum = 0;
	for(int k = 0; k < v.size(); k++)
	{
		sum += v[k];
		mn = min(mn, (k + 2)*(l - sum));
	}
	cout << mn << endl;
}

int main(void)
{
	ll t;
	cin >> t;
	while(t--)
	{
		solve();
	}

	return 0;
}