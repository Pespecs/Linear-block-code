#include <bits/stdc++.h>
using namespace std;

void solveA(bool fullOutput) {
    int n_codewords;
    if (!(cin >> n_codewords)) return;

    vector<string> codes(n_codewords);
    set<string> code_set;
    int len = 0;

    for (int i = 0; i < n_codewords; ++i) {
        cin >> codes[i];
        code_set.insert(codes[i]);
        len = codes[i].length();
    }

    if (fullOutput) {
        cout << "--- Step-by-step Solution for Part (a) ---\n";
        cout << "1. Checking for the all-zero codeword...\n";
    }

    string zero_code(len, '0');
    if (code_set.find(zero_code) == code_set.end()) {
        if (fullOutput) cout << "   -> All-zero codeword is MISSING.\nConclusion: The code is NOT linear.\n";
        else cout << "Not Linear\n";
        return;
    }

    if (fullOutput) {
        cout << "   -> All-zero codeword is present.\n";
        cout << "2. Checking closure under XOR for all pairs...\n";
    }

    for (int i = 0; i < n_codewords; ++i) {
        for (int j = i + 1; j < n_codewords; ++j) {
            string xor_res = "";
            for (int k = 0; k < len; ++k) {
                xor_res += (codes[i][k] == codes[j][k]) ? '0' : '1';
            }
            if (code_set.find(xor_res) == code_set.end()) {
                if (fullOutput) {
                    cout << "   -> Violation found: " << codes[i] << " XOR " << codes[j] << " = " << xor_res << " (Not in set).\n";
                    cout << "Conclusion: The code is NOT linear.\n";
                } else {
                    cout << "Not Linear\n";
                }
                return;
            }
        }
    }

    if (fullOutput) {
        cout << "   -> All pairs satisfy the closure property.\n";
        cout << "Conclusion: The code IS a Linear Block Code.\n";
    } else {
        cout << "Linear\n";
    }
}

void solveB(bool fullOutput) {
    int r, c; // r = n-k, c = n
    if (!(cin >> r >> c)) return;

    vector<vector<int>> H(r, vector<int>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> H[i][j];
        }
    }

    if (fullOutput) {
        cout << "--- Step-by-step Solution for Part (b) ---\n";
        cout << "Parity Check Matrix H (" << r << "x" << c << "):\n";
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) cout << H[i][j] << " ";
            cout << "\n";
        }
    }

    vector<vector<int>> mat = H;
    int lead = 0;
    vector<int> pivot_cols;

    for (int row = 0; row < r; ++row) {
        if (lead >= c) break;
        int i = row;
        while (mat[i][lead] == 0) {
            i++;
            if (i == r) {
                i = row;
                lead++;
                if (lead == c) break;
            }
        }
        if (lead >= c) break;

        swap(mat[i], mat[row]);
        pivot_cols.push_back(lead);

        for (int i = 0; i < r; ++i) {
            if (i != row && mat[i][lead] == 1) {
                for (int j = 0; j < c; ++j) {
                    mat[i][j] ^= mat[row][j];
                }
            }
        }
        lead++;
    }

    vector<int> free_cols;
    vector<bool> is_pivot(c, false);
    for (int pc : pivot_cols) is_pivot[pc] = true;
    for (int j = 0; j < c; ++j) {
        if (!is_pivot[j]) free_cols.push_back(j);
    }

    int k = free_cols.size();
    if (fullOutput) {
        cout << "1. Analyzing the null space of H...\n";
        cout << "   Code length (n): " << c << "\n";
        cout << "   Dimension of code (k): " << k << "\n";
        cout << "2. Generating all 2^k = " << (1ULL << k) << " codewords...\n";
    }

    vector<string> codewords;
    for (unsigned long long mask = 0; mask < (1ULL << k); ++mask) {
        vector<int> c_vec(c, 0);
        for (int i = 0; i < k; ++i) {
            if ((mask >> i) & 1) c_vec[free_cols[i]] = 1;
        }

        for (int row = 0; row < r; ++row) {
            int p_col = -1;
            for (int j = 0; j < c; ++j) {
                if (mat[row][j] == 1) { p_col = j; break; }
            }
            if (p_col != -1 && is_pivot[p_col]) {
                int sum = 0;
                for (int j = p_col + 1; j < c; ++j) {
                    if (mat[row][j] == 1) sum ^= c_vec[j];
                }
                c_vec[p_col] = sum;
            }
        }

        string s = "";
        for (int j = 0; j < c; ++j) s += to_string(c_vec[j]);
        codewords.push_back(s);
    }

    sort(codewords.begin(), codewords.end());

    if (fullOutput) {
        cout << "3. The complete set of codewords is:\n";
        for (const string& cw : codewords) cout << "   " << cw << "\n";
        cout << "Conclusion: Successfully generated " << codewords.size() << " codewords.\n";
    } else {
        for (const string& cw : codewords) cout << cw << "\n";
    }
}

int main() {
    freopen("ELE1319.in", "r", stdin);
    freopen("ELE1319.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char task, format;
    while (cin >> task >> format) {
        bool fullOutput = (format == 'F' || format == 'f');
        if (task == 'A' || task == 'a') {
            solveA(fullOutput);
        } else if (task == 'B' || task == 'b') {
            solveB(fullOutput);
        } else {
            cout << "Unknown Task Code.\n";
        }
    }

    return 0;
}
