#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

typedef unsigned long long ull;

// Complete the solve function below.
ull solve(int n, int m) {
    ull N = n;
    ull M = m;
    ull sum = 0;
    
    if(N < M) sum = N*(N+1)/2; //n < m
    else if(N == M) sum = (N-1)*N/2; //n == m
    else{//n > m
        ull x = N/M;
        sum = x*(M*(M-1)/2);
        ull X = N - (x*M);
        sum += (X*(X+1)/2);
    }
    
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        ull result = solve(n, m);

        fout << result << "\n";
    }

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
