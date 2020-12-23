// Question from SPOJ : A Needle in the Haystack
// Question link : https://www.spoj.com/problems/NHAY/
// Solved using string hashing and sliding window algorithm

#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll inv[1000001];   //to store inverse modulo
ll dp[1000001];    //to store hash values from(0,i)

ll power(ll a,ll n)
{
  ll res=1;
  while(n)
  {
    if(n&1)
    {
      res=(res*a)%mod;
    }
      n>>=1;
      a=(a*a)%mod;
  }
  return res;
}

void init(string s)
{
  ll p=31;
  ll p_power=1;
  inv[0]=1;
  dp[0]=(s[0]-'a'+1);

  for(ll i=1;i<s.length();i++)
  {
    char ch=s[i];
    p_power=(p_power*p)%mod;
    inv[i]=power(p_power,mod-2);
    dp[i]=(dp[i-1]+(ch-'a'+1)*p_power)%mod;
  }
}

ll substringHash(ll L ,ll R)
{
  ll res=dp[R];
  if(L>0)
  {
    res=(res-dp[L-1]+mod)%mod;
  }
  res=(res*inv[L])%mod;
  return res;
}

ll getHash(string key)
{
	ll value = 0;
	ll p = 31;
	ll p_power = 1;

	for(char ch : key)
	{
		value = (value + (ch - 'a' + 1)*p_power) % mod;
		p_power = (p_power * p) % mod;
	}

	return value;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string needle,haystack;
  ll n;

  while(cin>>n)
  {
    cin>>needle;
    cin>>haystack;

    ll hash_needle=getHash(needle);
    init(haystack);

    for(ll L=0,R=needle.length()-1;R<haystack.length();L++,R++)
    {
      if(substringHash(L,R)==hash_needle)
      {
        cout<<L<<endl;
      }
    }
    cout<<endl;
  }
}
