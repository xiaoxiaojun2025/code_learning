#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <sstream>

using namespace std;

class PropositionalFormula {
private:
    string formula;
    vector<char> variables;
    map<char, bool> valuation;
    vector<vector<bool>> truthTable;
    
    void extractVariables() {
        set<char> varSet;
        for (char c : formula) {
            if (c >= 'a' && c <= 'z') {
                varSet.insert(c);
            }
        }
        variables.assign(varSet.begin(), varSet.end());
        sort(variables.begin(), variables.end());
    }
    
    bool evaluate(const string& expr) {
        stack<bool> values;
        stack<char> operators;
        
        for (int i = 0; i < expr.length(); i++) {
            char c = expr[i];
            
            if (c == ' ') continue;
            
            if (c >= 'a' && c <= 'z') {
                values.push(valuation[c]);
            }
            else if (c == '0') values.push(false);
            else if (c == '1') values.push(true);
            else if (c == '!') operators.push(c);
            else if (c == '(') operators.push(c);
            else if (c == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    applyOperator(values, operators.top());
                    operators.pop();
                }
                operators.pop();
            }
            else {
                while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                    applyOperator(values, operators.top());
                    operators.pop();
                }
                operators.push(c);
            }
        }
        
        while (!operators.empty()) {
            applyOperator(values, operators.top());
            operators.pop();
        }
        
        return values.top();
    }
    
    int precedence(char op) {
        switch(op) {
            case '!': return 5;
            case '&': return 4;
            case '|': return 3;
            case '-': return 2;
            case '+': return 1;
            default: return 0;
        }
    }
    
    void applyOperator(stack<bool>& values, char op) {
        if (op == '!') {
            bool val = values.top(); values.pop();
            values.push(!val);
        } else {
            bool val2 = values.top(); values.pop();
            bool val1 = values.top(); values.pop();
            
            switch(op) {
                case '&': values.push(val1 && val2); break;
                case '|': values.push(val1 || val2); break;
                case '-': values.push(!val1 || val2); break;
                case '+': values.push(val1 == val2); break;
            }
        }
    }
    
    void buildTruthTable() {
        int n = variables.size();
        truthTable.clear();
        
        for (int i = 0; i < (1 << n); i++) {
            vector<bool> row;
            for (int j = 0; j < n; j++) {
                valuation[variables[j]] = (i >> (n - 1 - j)) & 1;
                row.push_back((i >> (n - 1 - j)) & 1);
            }
            
            bool result = evaluate(formula);
            row.push_back(result);
            truthTable.push_back(row);
        }
    }
    
    int getMintermIndex(const vector<bool>& values) {
        int index = 0;
        int n = variables.size();
        for (int i = 0; i < n; i++) {
            if (values[i]) {
                index += (1 << (n - 1 - i));
            }
        }
        return index;
    }
    
    int getMaxtermIndex(const vector<bool>& values) {
        int index = 0;
        int n = variables.size();
        for (int i = 0; i < n; i++) {
            if (!values[i]) {
                index += (1 << (n - 1 - i));
            }
        }
        return index;
    }

public:
    PropositionalFormula(const string& f) : formula(f) {
        string processed;
        for (int i = 0; i < f.length(); i++) {
            if (f[i] == '>') continue;
            processed += f[i];
        }
        formula = processed;
        
        extractVariables();
        buildTruthTable();
    }
    
    pair<string, string> getCanonicalForms() {
        vector<int> minterms;
        vector<int> maxterms;
        int n = variables.size();
        int totalTerms = (1 << n);
        
        for (const auto& row : truthTable) {
            bool result = row.back();
            vector<bool> varValues(row.begin(), row.begin() + n);
            
            if (result) {
                minterms.push_back(getMintermIndex(varValues));
            } else {
                maxterms.push_back(getMaxtermIndex(varValues));
            }
        }
        
        string pdnf, pcnf;
        
        // 主析取范式
        if (minterms.empty()) {
            pdnf = "0";
        } else {
            for (int i = 0; i < minterms.size(); i++) {
                pdnf += "m" + to_string(minterms[i]);
                if (i < minterms.size() - 1) {
                    pdnf += " ∨ ";
                }
            }
        }
        
        // 主合取范式
        if (maxterms.empty()) {
            pcnf = "1";
        } else {
            for (int i = 0; i < maxterms.size(); i++) {
                pcnf += "M" + to_string(maxterms[i]);
                if (i < maxterms.size() - 1) {
                    pcnf += " ∧ ";
                }
            }
        }
        
        return {pdnf, pcnf};
    }
};

int main() {
    string input;
    getline(cin, input);
    
    if (!input.empty() && input.back() == '\r') {
        input.pop_back();
    }
    
    PropositionalFormula pf(input);
    auto result = pf.getCanonicalForms();
    
    cout << result.first << " ; " << result.second << endl;
    
    return 0;
}