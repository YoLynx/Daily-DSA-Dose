// Problem Link : https://leetcode.com/problems/generate-parentheses/

class Solution {
public:

    void solve(string op, int open, int close, vector<string>& res) {
        if(open==0 && close==0) {
            res.push_back(op);
            return;
        }

        else if(open==close) {
            string op1=op;
            op1.push_back('(');
            solve(op1,open-1, close, res);
        } 

        else if(open==0) {
            string op1=op;
            op1.push_back(')');
            solve(op1, open, close-1, res);
        }

        else if(close==0) {
            string op1=op;
            op1.push_back('(');
            solve(op1, open-1, close, res);
        }

        else {
            string op1=op;
            string op2=op;
            op1.push_back('(');
            op2.push_back(')');
            solve(op1, open-1, close, res);
            solve(op2, open, close-1, res);
        }
    }

    vector<string> generateParenthesis(int n) {
        int open=n;
        int close=n;
        vector<string> res;
        string op="";
        solve(op, open, close, res);
        return res;
    }
};