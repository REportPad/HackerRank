#include <bits/stdc++.h>

using namespace std;

#define MOD (1000000000+7)

vector<string> split_string(string);

typedef unsigned long long ull;

// Complete the solve function below.
ull solve(vector<int> a) {
    int N = a.size();
    int num = 59;
    int d = (N-1)/num;
    ull ret = 1;
    
    int cnt = 0;
    for(int i=0; i < N; ++i){
        if(a[i]%2 == 0) ++cnt;
    }
    
    if(cnt == N){
        ret = pow(2, N) -1;
        return ret%MOD;
    }
    
    if(d == 0){
        ret = pow(2, N-1) -1;
    }
    else{
        ull p = pow(2, num);
        p %= MOD;
        for(int i=0; i < d; ++i){
            ret *= p;
            ret %= MOD;
        }
        ull temp = pow(2, (N-1) -d*num);
        temp %= MOD;
        ret *= temp;
        ret -= 1;
    }
     
    ret %= MOD;
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int a_count;
    cin >> a_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(a_count);

    for (int a_itr = 0; a_itr < a_count; a_itr++) {
        int a_item = stoi(a_temp[a_itr]);

        a[a_itr] = a_item;
    }

    ull result = solve(a);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
