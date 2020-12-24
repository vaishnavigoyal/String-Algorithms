// Problem: Given a string s of length n, consisting only of lowercase English letters, find the number of different substrings in this string.
//
// To solve this problem, we iterate over all substring lengths len = 1…n. For every substring length len we construct an array of hashes of all substrings of length len multiplied by the same power of p. The number of different elements in the array is equal to the number of distinct substrings of length len in the string. This number is added to the final answer.
// For convenience, we will use hash[i] as the hash of the prefix with i characters, and define hash[0]=0.

int count_unique_substrings(string s) {
    int n = s.length();

    const int p = 31;
    const int mod = 1e9 + 9;
    vector<long long> p_power(n);
    p_power[0] = 1;
    for (int i = 1; i < n; i++)
        p_power[i] = (p_power[i-1] * p) % mod;

    vector<long long> hash(n + 1, 0);
    for (int i = 0; i < n; i++)
        hash[i+1] = (hash[i] + (s[i] - 'a' + 1) * p_power[i]) % mod;

    int cnt = 0;
    for (int l = 1; l <= n; l++) {
        set<long long> hash_set;
        for (int i = 0; i <= n - l; i++) {
            long long cur_h = (hash[i + l] + mod - hash[i]) % mod;
            cur_h = (cur_h * p_power[n-i-1]) % mod;
            hash_set.insert(cur_h);
        }
        cnt += hash_set.size();
    }
    return cnt;
}
