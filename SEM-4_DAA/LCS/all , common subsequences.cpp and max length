/*
Based on the following logic, Given two sequences X =< x1, x2, ..., xm >
and Y =< y1, y2, ..., yn >, design a pseudocode that complies with the
following logic, to compute the maximum-length common subsequence of
X and Y .
 Generate all the subsequences of X
 Generate all the subsequences of Y
 Compute all the common subsequences of X and Y
 Identify the common subsequence of maximum length.
write c++ code

*/
// Function to generate all subsequences of a sequence
vector<vector<int>> generateSubsequences(vector<int> seq) {
    vector<vector<int>> subs;
    int n = seq.size();

    // Generate all possible subsequences
    for (int i = 0; i < (1 << n); i++) {
        vector<int> sub;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sub.push_back(seq[j]);
            }
        }
        subs.push_back(sub);
    }

    return subs;
}

// Function to compute the maximum-length common subsequence of X and Y
vector<int> maxCommonSubsequence(vector<int> X, vector<int> Y) {
    vector<vector<int>> Xsubs = generateSubsequences(X);
    vector<vector<int>> Ysubs = generateSubsequences(Y);

    vector<vector<int>> commonSubs;
    int maxLength = 0;

    // Find all common subsequences of X and Y
    for (vector<int> Xsub : Xsubs) {
        for (vector<int> Ysub : Ysubs) {
            if (Xsub == Ysub) {
                commonSubs.push_back(Xsub);
                maxLength = max(maxLength, (int)Xsub.size());
            }
        }
    }

    // Find the common subsequence of maximum length
    vector<int> maxSubseq;
    for (vector<int> sub : commonSubs) {
        if (sub.size() == maxLength) {
            maxSubseq = sub;
            break;
        }
    }

    return maxSubseq;
}
